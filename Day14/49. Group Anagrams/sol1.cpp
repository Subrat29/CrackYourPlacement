#include <bits/stdc++.h>
using namespace std;

// sc: n klogk (k - max length of string)
// tc: n*k

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto &&i : mp)
        ans.push_back(i.second);

    return ans;
}

int main()
{
    // a - 97
    // e - 101
    // t - 116

    string s = "ate";
    cout << 0 + s[0] << endl;

    return 0;
}