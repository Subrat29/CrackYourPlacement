#include <bits/stdc++.h>
using namespace std;

// len of s = m, len of t = n
// sc: m
// tc: m^n

int solve(string s, string t, int idx_s, int idx_t)
{
    if (idx_t == t.size())
        return 1;

    if (idx_s == s.size())
        return 0;

    int cnt = 0;
    for (int i = idx_s; i < s.size(); i++)
    {
        if (s[i] == t[idx_t])
            cnt += solve(s, t, i + 1, idx_t + 1);
    }
    return cnt;
}

int numDistinct(string s, string t)
{
    return solve(s, t, 0, 0);
}

int main()
{
    return 0;
}