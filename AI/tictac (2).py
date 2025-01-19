import random

# I am considering center and then corner tiles to be more important (As there are more winning combinations with them)
CENTER_POS = [(1,1)]
CORNER_POS = [(0,0), (0,2), (2,0), (2,2)]
MIDDLE_POS = [(1,0), (0,1), (2,1), (1,2)]
random.shuffle(CORNER_POS)
random.shuffle(MIDDLE_POS)
MOVE_PRIORITY_ORDER = CENTER_POS + CORNER_POS + MIDDLE_POS

# Considering that the possible scores are in interval [-1 , 1] , 3 and and -3 can be considered infinity
INF = 3

#Change to True to get AI to go first
AI_FIRST = False

def print_board(board):
    for row in board:
        print(" | ".join(row))
    print()

def is_winner(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(row[col] == player for row in board):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def is_full(board):
    return all(cell != " " for row in board for cell in row)

def evaluate(board , depth = 0):
    #depth = 0
    # I am adding depth to the eval, so the algorithm looks for the fastest win.
    if is_winner(board, "X"):
        return 1 - (0.01 * depth)
    elif is_winner(board, "O"):
        return -1 + (0.01 * depth)
    return 0

def minimax_alpha_beta(board, depth, alpha, beta, is_maximizing):
    score = evaluate(board , depth)
    if score != 0:
        return score
    if is_full(board):
        return 0
    
    if is_maximizing:
        max_eval = -INF
        for i , j in MOVE_PRIORITY_ORDER:
            if board[i][j] == " ": # I made version where we pass the available positions so we dont have to check already
                board[i][j] = "X" # filled positions ,but given that this is Python I think this optimization would only slow things down
                eval = minimax_alpha_beta(board, depth + 1, alpha, beta, False)
                board[i][j] = " "
                max_eval = max(max_eval, eval)
                alpha = max(alpha, eval)
                if beta <= alpha:
                    break

        return max_eval
    else:
        min_eval = INF
        for i , j in MOVE_PRIORITY_ORDER:
            if board[i][j] == " ":
                board[i][j] = "O"
                eval = minimax_alpha_beta(board, depth + 1, alpha, beta, True)
                board[i][j] = " "
                min_eval = min(min_eval, eval)
                beta = min(beta, eval)
                if beta <= alpha:
                    break
        return min_eval

def find_best_move(board, is_maximizing):
    best_score = -INF if is_maximizing else INF
    best_move = None
    for i, j in MOVE_PRIORITY_ORDER:
        if board[i][j] == " ":

            if is_maximizing:
                board[i][j] = "X"
            else:
                board[i][j] = "O"

            move_score = minimax_alpha_beta(board, 0, -INF, INF, not is_maximizing)
            board[i][j] = " "
            if (is_maximizing and move_score > best_score) or (not is_maximizing and move_score < best_score):
                best_score = move_score
                best_move = (i, j)
    return best_move


def play_tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    ai_turn = AI_FIRST

    while True:
        print_board(board)

        if is_winner(board, "X"):
            print("AI wins!")
            break
        if is_winner(board, "O"):
            print("Player wins!")
            break
        if is_full(board):
            print("Tie!")
            break

        if ai_turn:
            ai_move = find_best_move(board, is_maximizing=True)
            if ai_move:
                board[ai_move[0]][ai_move[1]] = "X"
                print(f"AI plays: ({ai_move[0] +1} , {ai_move[1] +1})")
        else:
            suggestion = find_best_move(board, is_maximizing=False)
            print(f"Suggested move: ({suggestion[0] +1} , {suggestion[1] +1})")
            player_move = tuple(map(int, input("Enter row and column (1-3): ").split()))
            if board[player_move[0] - 1][player_move[1] -1] == " ":
                board[player_move[0] -1][player_move[1] -1] = "O"
            else:
                print("Invalid move")
                continue

        ai_turn = not ai_turn

play_tic_tac_toe()
