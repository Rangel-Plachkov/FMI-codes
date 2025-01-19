import random
import math
import os
import csv

PATHS_PER_GEN = 1000
ROUNDUP_SYMS = 2
UPPER_BOUND = 100
LOWWER_BOUND = -100
GEN_COUNT = 100
MUTATION_PERCENT = 5

def gen_rnd_paths(N = 100 , name_file = None, cordinates_file = None):
    
    def gen_points(N):
        triples = []
        for i in range(1, N + 1):
            name = str(i)
            x = round(random.uniform(LOWWER_BOUND, UPPER_BOUND) ,ROUNDUP_SYMS)
            y = round(random.uniform(LOWWER_BOUND, UPPER_BOUND) ,ROUNDUP_SYMS)
            triples.append((name, x, y))
        return triples
    
    def gen_file_paths(names_file, cordinates_file):
        triples = []

        with open(names_file, 'r') as nf, open(cordinates_file, 'r') as cf:
            names_reader = csv.reader(nf)
            coords_reader = csv.reader(cf)
            
            for name_row, coord_row in zip(names_reader, coords_reader):
                name = name_row[0]
                x = float(coord_row[0])
                y = float(coord_row[1])
                
                triples.append((name, x, y))
        
        return triples

    if name_file != None:
        points_ls = gen_file_paths(name_file, cordinates_file)
    else:
        points_ls = gen_points(N)

    result = []
    for _ in range(PATHS_PER_GEN):
        random_path = points_ls[1:]
        random.shuffle(random_path)
        random_path = [points_ls[0]] + random_path
        result.append(random_path)
    return  result

def sum_wigths(path):
    def distance(a,b):
        sum = math.sqrt(   ((a[1] - b[1]) ** 2 ) + ((a[2] - b[2]) ** 2 ) )
        return sum
    return sum( distance(path[i-1] , path[i]) for i in range(1,len(path)) )

def chose_survivour(old_gen):
    #Chose survivour by comparing 2 random ones and appending the better path
    survivours = []
    random.shuffle(old_gen)
    middle = len(old_gen) // 2
    for i in range(middle):
        if sum_wigths(old_gen[i]) < sum_wigths(old_gen[middle + i]):
            survivours.append(old_gen[i])
        else:
            survivours.append(old_gen[i + middle])
    return survivours

def create_child(parent_a, parent_b):
    #Create child by getting subpath from A and concatinate to the remaining part from B
    child = []
    start = random.randint(0 , len(parent_a) -1 )
    finish = random.randint(start , len(parent_b))
    sub_path_from_a = parent_a[start:finish]

    remaining_path_from_b = list(item for item in parent_b if item not in sub_path_from_a)
    for i in range(0 , len(parent_a)):
        if start <= i < finish:
            child.append(sub_path_from_a.pop(0))
        else: 
            child.append(remaining_path_from_b.pop(0))
    return child

def crossover(survivours):
    children = survivours[:]
    middle = len(survivours) // 2
    for i in range(middle):
        parent_a , parent_b = survivours[i] , survivours[i + middle]
        children.append(create_child(parent_a , parent_b))
        children.append(create_child(parent_b , parent_a))

    return children


def mutation(generation):
    gen_mutation = []
    for path in generation:
        if random.uniform(0 , 100) <= MUTATION_PERCENT:
            index1, index2 = random.randint(1, len(path) - 1), random.randint(1, len(path) -1)
            path[index1],path[index2] = path[index2] , path[index1]
        gen_mutation.append(path)
    return gen_mutation

def gen_new_pop(old_gen):
    survivours = chose_survivour(old_gen)
    crossovers = crossover(survivours)
    new_pop = mutation(crossovers)
    return new_pop

def print_best_path(curr_gen , gen_count = None , just_sum = False):
    curr_min = sum_wigths(curr_gen[0])
    best_path = curr_gen[0]
    for path in curr_gen:
        curr_sum = sum_wigths(path)
        if curr_sum <= curr_min:
            curr_min = curr_sum
            best_path = path
    curr_min = round(curr_min , ROUNDUP_SYMS)
    names = [x[0] for x in best_path]

    out = f""
    if(gen_count != None):
        out += f"#{gen_count}:"

    if not just_sum:
        out += f"{names=} , "

    out += f"{curr_min=}"
    print(out)


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    names_file = os.path.join(script_dir, "uk12_name.csv")
    cords_file = os.path.join(script_dir, "uk12_xy.csv")

    curr_gen = gen_rnd_paths( name_file = names_file, cordinates_file = cords_file)
    # curr_gen = gen_rnd_paths(100)



    print_best_path(curr_gen , 0 , just_sum=True)
    for i  in range(GEN_COUNT-1):
        curr_gen = gen_new_pop(curr_gen)
        # print_best_path(curr_gen , i+1 , just_sum=True)
        if i == GEN_COUNT // 2:
            print_best_path(curr_gen , i+1 , just_sum=True) 
    
    print_best_path(curr_gen , i+1, just_sum=False)

if __name__ == "__main__":
    main()