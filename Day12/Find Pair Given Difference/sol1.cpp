#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: nlogn

// Binary Search : logn

int findPair(int n, int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = 1;
    while (right < n && left < n)
    {
        int diff = arr[right] - arr[left];
        if (diff == x && left != right)
            return 1;
        else if (diff > x)
            left++;
        else
            right++;
    }
    return -1;
}
int main()
{
    return 0;
}
