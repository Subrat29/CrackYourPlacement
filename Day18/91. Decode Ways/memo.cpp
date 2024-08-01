#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

vector<int> dp;

int solve(int i, string &s)
{
    int n = s.size();

    if (i == n)
        return 1;

    if (s[i] == '0')
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int singleDigit = solve(i + 1, s);
    int doubleDigit = 0;

    if (i + 1 < n)
    {
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
            doubleDigit = solve(i + 2, s);
    }
    return dp[i] = singleDigit + doubleDigit;
}

int numDecodings(string s)
{
    int n = s.size();
    dp.resize(n + 1, -1);

    return solve(0, s);
}

int main()
{
    string s = "234";
    return 0;
}