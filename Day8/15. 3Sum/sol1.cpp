#include <bits/stdc++.h>
using namespace std;

// tc: n^2
// sc: n + m (no of triplets)

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Approach: third = -(first + second)

vector<vector<int>> threeSum(vector<int> &num)
{
    int n = num.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(num[i] + num[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    return 0;
}