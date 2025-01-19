import random
import time

MAX_ITERATIONS = 10000

class QueenPuzzle:
    def __init__(self, N):


        self.N = N
        self.board = [0] * N  # board[x] = y would mean on row x in board there is queen on col y
        self.col_conf = [0] * N
        self.main_diag_conf = [0] * (N * 2 - 1) # \
        self.sec_diag_conf = [0] * (N * 2 - 1) # /
        self.number_of_conf = 0


        for i in range(self.N):
            col = random.randint(0, self.N - 1)
            self.board[i] = col
            self.col_conf[col] += 1
            self.main_diag_conf[i + col] += 1
            self.sec_diag_conf[self.N - 1 + i - col] += 1

        # self.number_of_conf = sum((conf - 1) for conf in self.col_conf + self.main_diag_conf + self.sec_diag_conf if conf > 1)
        # print(self.number_of_conf)

        self.number_of_conf = 0
        
        for c in self.col_conf:
            self.number_of_conf += c * (c - 1) / 2

        for c in self.main_diag_conf:
            self.number_of_conf += c * (c - 1) / 2
            
        for c in self.sec_diag_conf:
            self.number_of_conf += c * (c - 1) / 2
        # print(self.number_of_conf)




    def resolve(self):
        iter = 0
        while self.number_of_conf > 0 and iter < MAX_ITERATIONS:
            selected_idx = self.get_random_max_conf_queen_idx()
            min_conf_cols = []
            min_conf_count = float('inf')

            for i in range(self.N):
                if i != self.board[selected_idx]:
                    curr_conf_count = self.update_number_of_conf(selected_idx, self.board[selected_idx], i)
                    # get list of pos where the conflicts are lower (include positions where conf counts are equal)
                    if curr_conf_count < min_conf_count:
                        min_conf_count = curr_conf_count
                        min_conf_cols = [i]
                    elif curr_conf_count == min_conf_count:
                        min_conf_cols.append(i)

            if min_conf_count <= self.number_of_conf:
                new_col = random.choice(min_conf_cols)
                self.update_conflicts(selected_idx, self.board[selected_idx], new_col)
                self.board[selected_idx] = new_col
                self.number_of_conf = min_conf_count
            iter += 1

        if self.number_of_conf > 0:
            print("-1")

        if self.N <= 100:
            self.print_board()

    def get_number_of_particular_queen_conf(self, row):
        col = self.board[row]
        return (
            self.col_conf[col] - 1 +
            self.main_diag_conf[row + col] - 1 +
            self.sec_diag_conf[self.N - 1 + row - col] - 1
        )

    def get_random_max_conf_queen_idx(self):
        max_conflicting_rows = [0]
        max_conflicts = self.get_number_of_particular_queen_conf(0)
        
        for i in range(1, self.N):
            current_conflicts = self.get_number_of_particular_queen_conf(i)
            if current_conflicts > max_conflicts:
                max_conflicts = current_conflicts
                max_conflicting_rows = [i]
            elif current_conflicts == max_conflicts:
                max_conflicting_rows.append(i)
                
        return random.choice(max_conflicting_rows)

    def update_number_of_conf(self, row, old_col, new_col):
        new_number_of_conf = self.number_of_conf
        # Remove old confs
        new_number_of_conf -= (
            self.col_conf[old_col] - 1 +
            self.main_diag_conf[row + old_col] - 1 +
            self.sec_diag_conf[self.N - 1 + row - old_col] - 1
        )
        # add new confs
        new_number_of_conf += (
            self.col_conf[new_col] +
            self.main_diag_conf[row + new_col] +
            self.sec_diag_conf[self.N - 1 + row - new_col]
        )
        return new_number_of_conf

    def update_conflicts(self, row, old_col, new_col):
        # remove old confs (perm)
        self.col_conf[old_col] -= 1
        self.main_diag_conf[row + old_col] -= 1
        self.sec_diag_conf[self.N - 1 + row - old_col] -= 1

        # add new confs (perm)
        self.col_conf[new_col] += 1
        self.main_diag_conf[row + new_col] += 1
        self.sec_diag_conf[self.N - 1 + row - new_col] += 1

    def print_board(self):
        for i in range(self.N):
            row = ["*" if j == self.board[i] else "_" for j in range(self.N)]
            print("".join(row))
        print()

if __name__ == "__main__":
    N = int(input("N: "))
    task = QueenPuzzle(N)
    start = time.time()
    task.resolve()
    
    timer = time.time() - start
    timer = round(timer , 2)
    print(f"{timer=} sec")
