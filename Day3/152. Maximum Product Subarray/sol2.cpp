#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

// Integer Overflow

int maxProduct(vector<int> &nums)
{
    int maxProd = -10;
    int temp = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        temp = temp * nums[i];
        maxProd = max(temp, maxProd);

        if (temp == 0)
            temp = 1;
    }

    temp = 1;
    for (int i = 0; i < nums.size(); i++)
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