#include <bits/stdc++.h>
using namespace std;

// Approach: Bottom to up
// sc: n
// tc: n

int store[46] = {0};

int climbStairs(int n)
{
    store[1] = 1;
    store[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        store[i] = store[i - 1] + store[i - 2];
    }

    return store[n];
}

int main()
{
    return 0;
}