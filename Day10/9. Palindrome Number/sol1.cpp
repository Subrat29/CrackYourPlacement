#include <bits/stdc++.h>
using namespace std;

// tc: log base10 (n)
// sc: 1

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    long y = x;
    long res = 0;

    while (y)
    {
        res = res * 10 + y % 10;
        y /= 10;
    }
    return res == x;
}

int main()
{
    return 0;
}