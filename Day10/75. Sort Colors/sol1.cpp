#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n^2

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                int a = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = a;
            }
        }
    }
}

int main()
{
    // Input: nums = [2,0,2,1,1,0]
    // Output: [0,0,1,1,2,2]

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);

    return 0;
}