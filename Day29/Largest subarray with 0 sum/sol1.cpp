#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> hashMap;
        int sum = 0;
        int maxi = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxi = max(maxi, i + 1);
            }
            else
            {
                if (hashMap.find(sum) != hashMap.end())
                {
                    maxi = max(maxi, (i - hashMap[sum]));
                }
                else
                {
                    hashMap[sum] = i;
                }
            }
        }
        return maxi;
    }
};

int main()
{
    return 0;
}