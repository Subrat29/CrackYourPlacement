#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis)
{
    vis[i][j] = 2;

    int n = mat.size();
    int m = mat[0].size();

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    for (int k = 0; k < 4; k++)
    {
        int row = i + dx[k];
        int col = j + dy[k];

        if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == 0 && mat[row][col] == 'O')
        {
            dfs(row, col, mat, vis);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<char>> ans(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O')
            {
                dfs(i, j, mat, vis);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 2)
                ans[i][j] = 'O';
            else
                ans[i][j] = 'X';
        }
    }

    return ans;
}

int main()
{
    return 0;
}