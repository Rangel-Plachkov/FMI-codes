import csv
from collections import Counter
import math
import random
import os
import statistics

def load_data():
    file_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "house-votes-84.data")
    # column_names = [
    #     "party", "handicapped-infants", "water-project-cost-sharing", "adoption-of-the-budget-resolution",
    #     "physician-fee-freeze", "el-salvador-aid", "religious-groups-in-schools", "anti-satellite-test-ban",
    #     "aid-to-nicaraguan-contras", "mx-missile", "immigration", "synfuels-corporation-cutback",
    #     "education-spending", "superfund-right-to-sue", "crime", "duty-free-exports", 
    #     "export-administration-act-south-africa"
    # ]

    data = []
    with open(file_path, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(row)

    return data

def preprocess_data(data, mode):
    if mode == 0:
        return [[value if value != "?" else "abstained" for value in row] for row in data]
    elif mode == 1:
        # Filling with the most common value
        column_modes = {}
        for col_idx in range(1, len(data[0])):
            values = [row[col_idx] for row in data if row[col_idx] != "?"]
            column_modes[col_idx] = Counter(values).most_common(1)[0][0]
        return [
            [
                value if value != "?" else column_modes[idx]
                for idx, value in enumerate(row)
            ]
            for row in data
        ]
    elif mode == 2:
        #Fill keeping the distribution
        column_distributions = {}
        
        for col_idx in range(1, len(data[0])):
            values = [row[col_idx] for row in data if row[col_idx] != "?"]
            value_counts = Counter(values)
            #total_count = sum(value_counts.values())
            #print(total_count)
            column_distributions[col_idx] = value_counts
        
        return [
            [
                value if value != "?" else random.choices(
                    list(column_distributions[idx].keys()), 
                    weights=column_distributions[idx].values(), 
                    k=1
                )[0]
                for idx, value in enumerate(row)
            ]
            for row in data
        ]


def stratified_split(data, k=10):
    class_groups = {}
    for row in data:
        cls = row[0]
        if cls not in class_groups:
            class_groups[cls] = []
        class_groups[cls].append(row)
    
    folds = [[] for _ in range(k)]
    for group in class_groups.values():
        random.shuffle(group)
        for i, sample in enumerate(group):
            folds[i % k].append(sample)
    
    return folds



def calculate_prior_probabilities(data):
    total_count = len(data)
    
    class_counts = Counter(row[0] for row in data)

    prior_probabilities = {
        cls: count / total_count
        for cls, count in class_counts.items()
    }

    return prior_probabilities

def calculate_likelihoods(data):
    likelihoods = {}
    feature_counts = {}

    for row in data:
        cls = row[0]
        if cls not in feature_counts:
            feature_counts[cls] = {}
        for idx, value in enumerate(row[1:], start=1):
            if idx not in feature_counts[cls]:
                feature_counts[cls][idx] = {}
            if value not in feature_counts[cls][idx]:
                feature_counts[cls][idx][value] = 1
            feature_counts[cls][idx][value] += 1

    for cls in feature_counts:
        likelihoods[cls] = {}
        for idx in feature_counts[cls]:
            likelihoods[cls][idx] = {}
            total = sum(feature_counts[cls][idx].values())
            for value, count in feature_counts[cls][idx].items():
                likelihoods[cls][idx][value] = count / total

    return likelihoods


def predict(data, priors, likelihoods, smoothing=1e-6):
    predictions = []
    for row in data:
        class_scores = {}
        for cls, prior in priors.items():
            score = math.log(prior)
            for idx, value in enumerate(row[1:], start=1):
                score += math.log(
                    likelihoods[cls][idx].get(value, smoothing)
                )
            class_scores[cls] = score
        predictions.append(max(class_scores, key=class_scores.get))

    return predictions

def evaluate(y_true, y_pred):
    correct = sum(1 for true, pred in zip(y_true, y_pred) if true == pred)
    return correct / len(y_true)



def cross_validation(data, k=10):
    folds = stratified_split(data, k=k)
    accuracies = []

    for i in range(k):
        validation_data = folds[i]

        train_data = [row for j, fold in enumerate(folds) if j != i for row in fold]

        priors = calculate_prior_probabilities(train_data)
        likelihoods = calculate_likelihoods(train_data)

        y_val_true = [row[0] for row in validation_data]
        val_predictions = predict(validation_data, priors, likelihoods)

        accuracy = evaluate(y_val_true, val_predictions)
        accuracies.append(accuracy * 100)

    return accuracies




def main():
    mode = int(input("Mode: "))
    data = load_data()

    data = preprocess_data(data, mode)

    folds = stratified_split(data, k=5)
    test_data = folds[0]
    train_folds = folds[1:]

    full_train_data = [row for fold in train_folds for row in fold]
    cv_accuracies = cross_validation(full_train_data, k=10)

    avg_accuracy = statistics.mean(cv_accuracies)
    std_dev = statistics.stdev(cv_accuracies)
    print("\n10-Fold Cross-Validation Results (Training Set):")
    for i, acc in enumerate(cv_accuracies, start=1):
        print(f"    Accuracy Fold {i}: {acc:.2f}%")
    print(f"\n    Average Accuracy: {avg_accuracy:.2f}%")
    print(f"    Standard Deviation: {std_dev:.2f}%")

    priors = calculate_prior_probabilities(full_train_data)
    likelihoods = calculate_likelihoods(full_train_data)
    y_test_true = [row[0] for row in test_data]
    test_predictions = predict(test_data, priors, likelihoods)
    test_accuracy = evaluate(y_test_true, test_predictions) * 100
    print("\nTest Set Accuracy:")
    print(f"    Accuracy: {test_accuracy:.2f}%")


if __name__ == "__main__":
    main()
