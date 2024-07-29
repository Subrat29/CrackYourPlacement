#include <bits/stdc++.h>
using namespace std;

// sc: n + m
// tc: 2^(m+n)

void solve(int m, int n, int i, int j, int &cnt)
{
    if (i >= m || j >= n)
        return;
    if (i == m - 1 && j == n - 1)
        cnt++;
    // Down
    solve(m, n, i + 1, j, cnt);
    // Right
    solve(m, n, i, j + 1, cnt);
}

int uniquePaths(int m, int n)
{
    int cnt = 0;
    solve(m, n, 0, 0, cnt);
    return cnt;
}

int main()
{
    cout << uniquePaths(3, 7);
    return 0;
}