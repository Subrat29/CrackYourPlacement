#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(9^(n*n)), where n is the size of the board (n=9 in standard Sudoku).
// Space Complexity: O(1) (ignoring the recursion stack).

bool isSafe(vector<vector<char>> &board, int row, int col, int val)
{
    int n = board.size();
    char ch = val + '0'; // Convert integer val to character for comparison.
    for (int i = 0; i < n; i++)
    {
        // row check
        if (board[row][i] == ch)
            return false;
        // col check
        if (board[i][col] == ch)
            return false;
        // matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(board, i, j, val))
                    {
                        board[i][j] = val + '0'; // Convert integer val to character for the board.
                        if (solve(board))
                            return true;
                        board[i][j] = '.'; // Backtrack by resetting the cell.
                    }
                }
                return false; // Return false if no valid number is found for this cell.
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    return 0;
}
