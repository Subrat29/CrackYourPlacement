#include <bits/stdc++.h>
using namespace std;

// sc: n + no of quadlets
// tc: n^3

// a + b + c = target - d

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_set<long long> hasset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long x = target - (sum);
                if (hasset.find(x) != hasset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)x};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hasset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    return 0;
}