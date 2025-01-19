def frog_puzzle(N):
    start = ['>'] * N + ['_'] + ['<'] * N
    end = ['<'] * N + ['_'] + ['>'] * N

    solutions = []
    visited = set()

    def dfs(board, path):
        if board == end:
            solutions.append(path + ["".join(board)])
            return
        
        visited.add("".join(board))
        
        empty_index = board.index('_')

        if empty_index > 0 and board[empty_index - 1] == '>':
            new_board = board[:]
            new_board[empty_index], new_board[empty_index - 1] = new_board[empty_index - 1], new_board[empty_index]
            if "".join(new_board) not in visited:
                dfs(new_board, path + ["".join(board)])
        
        if empty_index > 1 and board[empty_index - 2] == '>':
            new_board = board[:]
            new_board[empty_index], new_board[empty_index - 2] = new_board[empty_index - 2], new_board[empty_index]
            if "".join(new_board) not in visited:
                dfs(new_board, path + ["".join(board)])

        if empty_index < len(board) - 1 and board[empty_index + 1] == '<':
            new_board = board[:]
            new_board[empty_index], new_board[empty_index + 1] = new_board[empty_index + 1], new_board[empty_index]
            if "".join(new_board) not in visited:
                dfs(new_board, path + ["".join(board)])

        if empty_index < len(board) - 2 and board[empty_index + 2] == '<':
            new_board = board[:]
            new_board[empty_index], new_board[empty_index + 2] = new_board[empty_index + 2], new_board[empty_index]
            if "".join(new_board) not in visited:
                dfs(new_board, path + ["".join(board)])

    dfs(start, [])
    return solutions


def main():
    N = 3
    result = frog_puzzle(N)
    for step in result[0]:
        print(step)


if __name__ == "__main__":
    main()