package app;

// Не успях да се оправя с линкването на jar файла, затова съм копирал класовете от jar в src/app
import jar.*;


import java.util.ArrayList;

import java.util.List;
import java.util.Collections;
import java.util.Random;
import java.util.Arrays;
import java.util.Map;
import java.util.stream.Collectors;

public class FoodStatistics {
    private List<FoodInstance> data;
    public static void main(String[] args) {
        /*
        for (Food food : Food.FOOD_PRODUCTS) {
            System.out.println(food.toString());
        }
        */

        FoodStatistics foodStatistics = new FoodStatistics();

        foodStatistics.generateData();
        foodStatistics.printFoodCategories();
        foodStatistics.groupByFoodCount();
    }
    public FoodStatistics() {
        this.data = new ArrayList<>();
        data.add(new FoodInstance(0, "Apple", 1.00));
        data.add(new FoodInstance(1, "Banana", 2.00));
        data.add(new FoodInstance(2, "Orange", 3.00));
        data.add(new FoodInstance(3, "Pineapple", 4.00));
        data.add(new FoodInstance(4, "Watermelon", 5.00));
        data.add(new FoodInstance(5, "Strawberry", 6.00));
        data.add(new FoodInstance(6, "Blueberry", 7.00));
        data.add(new FoodInstance(7, "Raspberry", 8.00));
        data.add(new FoodInstance(8, "Blackberry", 9.00));
        data.add(new FoodInstance(9, "Cherry", 10.00));

    }

    public void generateData() {
        Random random = new Random();

        for (int i = 0; i < 60; i++) {
            int randomKey = random.nextInt(Food.FOOD_PRODUCTS.length);
            Food food = Food.FOOD_PRODUCTS[randomKey];
            double randomPrice = 1.00 + (24.00 * random.nextDouble());

            FoodInstance foodInstance = new FoodInstance(randomKey, food.getName(), randomPrice);
            data.add(foodInstance);
        }

        Collections.sort(data);

        for (FoodInstance foodInstance : data) {
            System.out.println(foodInstance.toString());
        }
    }
    public void printFoodCategories() {
        Arrays.stream(FoodCategory.values())
                .sorted((category1, category2) -> category1.name().compareTo(category2.name()))
                .forEach(category -> System.out.println(category + " " + category.getCategoryName()));
    }
    public void groupByFoodCount() {
        Map<String, Long> foodCountMap = data.stream()
                .collect(Collectors.groupingBy(foodInstance -> Food.FOOD_PRODUCTS[foodInstance.getFoodKey()]
                                .getName(),
                        Collectors.counting()));

        foodCountMap.entrySet().stream()
                .sorted((entry1, entry2) -> entry2.getValue().compareTo(entry1.getValue()))
                .forEach(entry -> System.out.println(entry.getKey() + " has " + entry.getValue() + " instances in data."));
    }



}
