#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

// Integer Overflow

int maxProduct(vector<int> &nums)
{
    double maxProd = -10;
    double temp = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        temp = temp * nums[i];
        maxProd = max(temp, maxProd);

        if (temp == 0)
            temp = 1;
    }

    temp = 1;
    for (int i = nums.size()-1; i >= 0 ; i--)
    {
        temp = temp * nums[i];
        maxProd = max(temp, maxProd);

        if (temp == 0)
            temp = 1;
    }
    return maxProd;
}

int main()
{
    return 0;
}