def solve_n_queens(n):
    result = []
    board = [-1]*n
    def is_valid(board, row, col):
        for i in range(row):
            if board[i] == col or abs(row - i) == abs(col - board[i]): # 采用比较绝对值的方式同时比较主对角线和副对角线
                return False
        return True
    def print_solution(board, sol_num):
        print(f"解法 {sol_num}: ")
        for current_col in board:
            line = ['□'] * n
            line[current_col] = 'Q'
            print(' '.join(line))
        print()
    def backtrack(board, row):
        if row == n:
            result.append(board.copy())
            print_solution(board, len(result))
            return
        for col in range(n):
            if is_valid(board, row, col):
                board[row] = col
                backtrack(board, row+1)
                board[row] = -1

    backtrack(board, 0)
    print(f"共找到{len(result)}种解法")
    return result

solutions = solve_n_queens(8)