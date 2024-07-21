#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

// Approach: We can find out the no of 1's in binary number n by binary number n/2 + add 1 if n is odd else add 0.
// devide by 2 means the right shift a bit

vector<int> countBits(int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = dp[i / 2];
        else
            dp[i] = 1 + dp[i / 2];
    }
    return dp;
}

int main()
{
    return 0;
}