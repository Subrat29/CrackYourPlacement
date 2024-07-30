#include <bits/stdc++.h>
using namespace std;

// In depth-first search (DFS), the time complexity is b^m),
// where b is the branching factor and m is the maximum depth of the tree

// sc: l (word length)
// tc: m*n*4^l

bool solve(int i, int j, int k, vector<vector<char>> &board, string &word)
{
    if (k == word.length())
        return true;

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k])
        return false;

    char temp = board[i][j];
    board[i][j] = '#';

    bool down = solve(i + 1, j, k + 1, board, word);
    bool right = solve(i, j + 1, k + 1, board, word);
    bool up = solve(i - 1, j, k + 1, board, word);
    bool left = solve(i, j - 1, k + 1, board, word);

    board[i][j] = temp;

    return down || right || up || left;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    return 0;
}