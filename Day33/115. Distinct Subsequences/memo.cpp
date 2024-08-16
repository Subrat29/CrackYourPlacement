#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

vector<vector<int>> dp;

int solve(string &s, string &t, int idx_s, int idx_t)
{
    if (idx_t == t.size())
        return 1;

    if (idx_s == s.size())
        return 0;

    if (dp[idx_s][idx_t] != -1)
        return dp[idx_s][idx_t];

    int cnt = 0;
    for (int i = idx_s; i < s.size(); i++)
    {
        if (s[i] == t[idx_t])
            cnt += solve(s, t, i + 1, idx_t + 1);
    }
    return dp[idx_s][idx_t] = cnt;
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    dp.resize(n, vector<int>(m, -1));

    return solve(s, t, 0, 0);
}

int main()
{
    return 0;
}