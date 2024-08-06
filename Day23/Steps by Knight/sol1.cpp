#include <bits/stdc++.h>
using namespace std;

// Dfs solution complexity
// sc: 8^(n*n) (for n*n chessboard)
// tc: n*n

// Bfs solution complexity
// sc: n*n
// tc: n*n

class Cell
{
public:
    int x;
    int y;
    int cnt;
};

bool isValid(int &x, int &y, int &N, vector<vector<int>> &vis)
{
    if (x < 0 || y < 0 || x > N || y > N || vis[x][y] == true)
        return false;
    return true;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    // knight current Location
    int kx = KnightPos[0];
    int ky = KnightPos[1];

    // Target Location
    int Tx = TargetPos[0];
    int Ty = TargetPos[1];

    queue<Cell> q;
    q.push({kx, ky, 0});
    vis[kx][ky] = 1;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if (x == Tx && y == Ty)
            return cnt;

        for (int i = 0; i < moves.size(); i++)
        {
            int a = x + moves[i][0];
            int b = y + moves[i][1];

            if (isValid(a, b, N, vis))
            {
                vis[a][b] = 1;
                q.push({a, b, cnt + 1});
            }
        }
    }
    return -1;
}
int main()
{
    return 0;
}