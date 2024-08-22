#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

// User function Template for C++

class Solution
{
public:
    bool check(int n, int k, vector<int> stalls, int mid)
    {
        int c = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= mid)
            {
                last = stalls[i];
                c++;
                if (c == k)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int l = 0;
        int h = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (check(n, k, stalls, mid))
            {

                ans = mid;
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}