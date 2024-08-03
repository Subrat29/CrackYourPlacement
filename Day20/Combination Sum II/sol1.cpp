#include <bits/stdc++.h>
using namespace std;

// sc: 2^n*n
// tc: nlogn + 2^n*n

void solve(int idx, int n, int target, vector<int> &combination, vector<vector<int>> &ans, vector<int> &arr)
{
    if (target == 0)
    {
        ans.push_back(combination);
        return;
    }

    if (idx >= n || target < 0)
        return;

    for (int i = idx; i < n; i++)
    {
        // CONFUSION: i > idx hi hoga naki i > 0 because agr hm i>0 lege to koi bhi duplicate elem combination me part nhi le payega but hme ye krna h ki combination
        // duplicate na ho naki elem

        if (i > idx && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        combination.push_back(arr[i]);
        solve(i + 1, n, target - arr[i], combination, ans, arr);
        combination.pop_back();
    }
}

vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> combination;

    solve(0, n, k, combination, ans, arr);
    return ans;
}

int main()
{
    return 0;
}
