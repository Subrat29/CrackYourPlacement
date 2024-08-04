#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: m*n

#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

int longestCommonSubstr(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    vector<int> curr(n + 1, 0);
    vector<int> prev(n + 1, 0);

    int maxLen = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                maxLen = max(maxLen, curr[j]);
            }
            else
                curr[j] = 0; // now its imp
        }
        prev = curr;
    }
    return maxLen;
}

int main()
{
    return 0;
}

int main()
{
    return 0;
}