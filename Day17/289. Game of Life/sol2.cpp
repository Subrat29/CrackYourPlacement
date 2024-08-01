#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: m*n

void gameOfLife(vector<vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();

    // Direction vectors for the 8 neighbors
    vector<pair<int, int>> dir = {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            int live = 0;
            for (const auto &d : dir)
            {
                int newRow = i + d.first;
                int newCol = j + d.second;

                if (newRow < 0 || newRow >= row || newCol < 0 || newCol >= col)
                    continue;

                if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2)
                    ++live;
            }

            // Update the board: 3 represents a cell that was dead but comes to life
            if (board[i][j] == 0 && live == 3)
                board[i][j] = 3;
            // Update the board: 2 represents a cell that was alive but dies
            if (board[i][j] == 1 && (live < 2 || live > 3))
                board[i][j] = 2;
        }
    }

    // Final pass to update the board to the final state
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            board[i][j] %= 2;
        }
    }
}

int main()
{
    return 0;
}