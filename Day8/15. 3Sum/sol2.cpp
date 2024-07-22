#include <bits/stdc++.h>
using namespace std;

// sc: m = no of triplets
// tc: nlogn + n^2

// Input: nums = [-1,0,1,2,-1,-4]  => [-4,-1,-1,0,1,2]
// Output: [[-1,-1,2],[-1,0,1]]

vector<vector<int>> threeSum(vector<int> &num)
{
    int n = num.size();
    vector<vector<int>> ans;

    sort(num.begin(), num.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i != 0 && num[i] == num[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = num[i] + num[j] + num[k];
            if (sum == 0)
            {
                ans.push_back({num[i], num[j], num[k]});
                j++;
                k--;

                while (j < k && num[j] == num[j - 1])
                {
                    j++;
                }
                while (j < k && num[k] == num[k + 1])
                {
                    k--;
                }
            }
            else if (sum > 0)
                k--;
            else
                j++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}