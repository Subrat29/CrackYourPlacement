#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

int climbStairs(int n)
{
    int prev2 = 1;
    int prev1 = 2;

    if (n == 1 || n == 2)
        return n;

    for (int i = 3; i <= n; i++)
    {
        int temp = prev1;
        prev1 += prev2;
        prev2 = temp;
    }
    return prev1;
}

int main()
{
    return 0;
}