#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int idx = nums[i] - 1;
        if (nums[idx] < 0)
            ans.push_back(idx);
        else
            nums[idx] = -nums[idx];
    }
    return ans;
}

int main()
{
    return 0;
}