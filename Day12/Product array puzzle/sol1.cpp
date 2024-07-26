#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    long long int totProd = 1;
    bool isProdZero = false;
    int onlyOneZero = 0;

    for (auto &&i : nums)
    {
        if (i == 0)
        {
            onlyOneZero++;
            isProdZero = true;
            continue;
        }
        totProd *= i;
    }

    if (onlyOneZero > 1)
    {
        vector<long long int> ans(n, 0);
        return ans;
    }

    vector<long long int> ans;

    if (!isProdZero)
    {
        for (auto &&i : nums)
            ans.push_back(totProd / i);
    }
    else
    {
        for (auto &&i : nums)
        {
            if (i == 0)
                ans.push_back(totProd);
            else
                ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    return 0;
}