#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {

            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }

            int singleDigit = dp[i + 1];
            int doubleDigit = 0;

            if (i + 1 < n)
            {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                    doubleDigit = dp[i + 2];
            }
            dp[i] = singleDigit + doubleDigit;
        }
        return dp[0];
    }
};

int main()
{
    string s = "234";
    return 0;
}