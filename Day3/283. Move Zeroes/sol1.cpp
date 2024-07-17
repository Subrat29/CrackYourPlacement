#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

void moveZeroes(vector<int> &nums)
{
    int x = 0;
    int y = 0;
    int countZero = 0;

    while (y < nums.size())
    {
        if (nums[y])
        {
            nums[x] = nums[y];
            x++;
        }
        else
        {
            countZero++;
        }
        y++;
    }

    while (x < nums.size())
    {
        nums[x] = 0;
        x++;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ", ";
    }
    return 0;
}