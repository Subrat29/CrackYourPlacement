#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

long long findMinDiff(vector<long long> a, long long n, long long m)
{

    // sort given vector
    sort(a.begin(), a.end());

    long long minDiff = INT_MAX;

    for (int i = 0; i <= a.size() - m; i++)
    {
        // check every window i to i-m-1
        long long window = a[i + m - 1] - a[i];

        if (window < minDiff)
        {
            minDiff = window;
        }
    }
    return minDiff;
}

int main()
{
    return 0;
}