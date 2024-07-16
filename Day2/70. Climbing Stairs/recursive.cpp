#include <bits/stdc++.h>
using namespace std;

// Actually, This question is nothing but the fibonacci series (not exactly)
// Fibo series: 0 1 1 2 3 5 8 13 21 (n >= 0)
// This series:   1 2 3 5 8 13 21 (n >= 1)

// Approach: Top to Bottom
// sc: n (call stack)
// tc: 2^n (every call has 2 sub calls)

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;

    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    return 0;
}