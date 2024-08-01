#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

void gameOfLife(vector<vector<int>> &board)
{
    int row = board.size();
    int col = board[0].size();

    // Create a copy of the board to store the next state
    vector<vector<int>> nextState = board;

    vector<pair<int, int>> pos = {
        {1, 0},  // right
        {-1, 0}, // left
        {0, 1},  // down
        {0, -1}, // up
        {1, 1},  // down-right
        {1, -1}, // down-left
        {-1, 1}, // up-right
        {-1, -1} // up-left
    };

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int totalLiveCells = 0;
            for (const auto &p : pos)
            {
                int x = i + p.first;
                int y = j + p.second;

                if (x < 0 || x >= row || y < 0 || y >= col)
                    continue;

                if (board[x][y] == 1)
                    totalLiveCells++;
            }

            // live cell
            if (board[i][j] == 1)
            {
                if (totalLiveCells < 2 || totalLiveCells > 3)
                    nextState[i][j] = 0;
            }
            // dead cell
            else
            {
                if (totalLiveCells == 3)
                    nextState[i][j] = 1;
            }
        }
    }

    // Update the original board with the next state
    board = nextState;
}

int main()
{
    return 0;
}