#include <bits/stdc++.h>
using namespace std;

// Approach: Top to Bottom
// sc: n + n = n
// tc: n

int store[46] = {0};

int climbStairs(int n)
{
    if (n == 1 || n == 2)
        return n;

    // If store has the value of intermediate stairs then dont go for function call just return value from store.
    if (store[n])
        return store[n];

    // first store the intermediate stairs then return
    store[n] = climbStairs(n - 1) + climbStairs(n - 2);
    return store[n];
}

int main()
{
    return 0;
}