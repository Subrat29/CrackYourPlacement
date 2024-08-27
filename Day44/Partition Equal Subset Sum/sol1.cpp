#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class Solution
{
public:
    void solve(vector<int> &arr, int idx, vector<int> &left, vector<int> &right, int s1, int s2, int &diff, vector<bool> &res)
    {
        if (idx == arr.size())
        {
            if (left.size() == (arr.size() + 1) / 2)
            {
                if (abs(s1 - s2) < diff)
                {
                    diff = abs(s1 - s2);
                    for (int i = 0; i < arr.size(); i++)
                        res[i] = false;

                    for (int i = 0; i < left.size(); i++)
                        res[left[i]] = true;
                }
            }
            return;
        }
        left.push_back(idx);
        solve(arr, idx + 1, left, right, s1 + arr[idx], s2, diff, res);
        left.pop_back();

        right.push_back(idx);
        solve(arr, idx + 1, left, right, s1, s2 + arr[idx], diff, res);
        right.pop_back();
    }
    vector<vector<int>> minDifference(vector<int> &arr, int n)
    {
        // Code here
        vector<int> left;
        vector<int> right;
        vector<bool> res(n, false);
        int diff = INT_MAX;
        solve(arr, 0, left, right, 0, 0, diff, res);
        left.clear();
        right.clear();
        for (int i = 0; i < n; i++)
        {
            if (res[i] == true)
                left.push_back(arr[i]);
            else
                right.push_back(arr[i]);
        }
        return {left, right};
    }
};

int main()
{
    return 0;
}