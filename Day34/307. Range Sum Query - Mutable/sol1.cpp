#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class NumArray
{
public:
    vector<int> arr;
    NumArray(vector<int> &nums)
    {
        arr = nums;
    }

    void update(int index, int val)
    {
        arr[index] = val;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            sum += arr[i];
        }
        return sum;
    }
};

int main()
{
    return 0;
}