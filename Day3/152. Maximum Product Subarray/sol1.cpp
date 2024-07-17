#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n^2

// Interger Overflow
// Time limit exceed

int maxProduct(vector<int> &nums)
{
    int maxProd = -10;
    for (int i = 0; i < nums.size(); i++)
    {
        int temp = 1;
        for (int j = i; j < nums.size(); j++)
        {
            temp = temp * nums[j];
            maxProd = max(maxProd, temp);
        }
    }
    return maxProd;
}

int main()
{
    return 0;
}