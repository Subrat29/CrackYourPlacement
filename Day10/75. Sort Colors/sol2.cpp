#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

// Approach: 3 Pointer

void sortColors(vector<int> &nums)
{
    int s = 0;
    int mid = 0;
    int e = nums.size() - 1;

    while (mid <= e) // = sign is necessary
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[s]);
            mid++;
            s++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[e]);
            e--;
        }
    }
}

int main()
{
    return 0;
}