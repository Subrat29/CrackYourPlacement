#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: m + n

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int k = n + m - 1;
    m = m - 1;
    n = n - 1;

    while (m >= 0 && n >= 0)
    {
        if (nums1[m] > nums2[n])
            nums1[k--] = nums1[m--];
        else
            nums1[k--] = nums2[n--];
    }

    while (m >= 0)
    {
        nums1[k--] = nums1[m--];
    }

    while (n >= 0)
    {
        nums1[k--] = nums2[n--];
    }
}

int main()
{
    return 0;
}