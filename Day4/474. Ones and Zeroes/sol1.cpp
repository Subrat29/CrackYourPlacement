#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n*2^n (calculating no of 1s and 0s * each element there are 2 possiblities)

int result = 0;

void solve(vector<string> &strs, int max0, int max1, int noOf1s, int noOf0s, int idx, vector<string> &ans)
{
    if (idx >= strs.size())
    {
        int maxLen = ans.size();
        result = max(result, maxLen);
        return;
    }

    string s = strs[idx];
    int s_0s = 0, s_1s = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            s_0s++;
        else
            s_1s++;
    }

    bool is0sValid = (noOf0s + s_0s <= max0) ? true : false;
    bool is1sValid = (noOf1s + s_1s <= max1) ? true : false;

    if (is0sValid && is1sValid)
    {
        // take
        ans.push_back(s);
        solve(strs, max0, max1, noOf1s + s_1s, noOf0s + s_0s, idx + 1, ans);
        ans.pop_back();
    }
    // not take
    solve(strs, max0, max1, noOf1s, noOf0s, idx + 1, ans);
}

int findMaxForm(vector<string> &strs, int max0, int max1)
{
    int noOf1s = 0;
    int noOf0s = 0;
    vector<string> ans;

    for (int i = 0; i < strs.size(); i++)
    {
        solve(strs, max0, max1, noOf1s, noOf0s, i, ans);
    }
    return result;
}

int main()
{
    return 0;
}