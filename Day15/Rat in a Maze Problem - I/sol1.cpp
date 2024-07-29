#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: 4^(m*n)

void solve(int i, int j, vector<vector<int>> &mat, string &s, vector<string> &ans)
{
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] == 0)
        return;

    if (i == mat.size() - 1 && j == mat[0].size() - 1)
        ans.push_back(s);

    mat[i][j] = 0;

    // UP
    s.push_back('U');
    solve(i - 1, j, mat, s, ans);
    s.pop_back();

    // DOWN
    s.push_back('D');
    solve(i + 1, j, mat, s, ans);
    s.pop_back();

    // LEFT
    s.push_back('L');
    solve(i, j - 1, mat, s, ans);
    s.pop_back();

    // RIGHT
    s.push_back('R');
    solve(i, j + 1, mat, s, ans);
    s.pop_back();

    mat[i][j] = 1;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    if (mat[0][0] == 0)
        return {};

    string s = "";
    vector<string> ans;
    solve(0, 0, mat, s, ans);

    return ans;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    findPath(mat);
    return 0;
}