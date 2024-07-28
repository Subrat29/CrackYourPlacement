#include <bits/stdc++.h>
using namespace std;

// tc: 3^n
// sc: n

int solve(int n, int x, int y, int z)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;

    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    return max(a, max(b, c));
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int ans = solve(n, x, y, z);
    return ans < 0 ? 0 : ans;
}

int main()
{
    return 0;
}