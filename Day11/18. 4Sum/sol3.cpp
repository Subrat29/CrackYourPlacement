#include <bits/stdc++.h>
using namespace std;

// sc: no of quads (only for returing the answer not to solve the problem)
// tc: nlogn + n2 * n(At max visit every elem once) ~ n3

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                long sum = nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];

                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}