#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

int maxArea(vector<int> &height)
{
    int n = height.size();
    int i = 0;
    int j = n - 1;
    int maxiArea = 0;

    while (i < n && j >= 0 && i != j)
    {
        int l = min(height[i], height[j]);
        int b = j - i;
        maxiArea = max(maxiArea, l * b);
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return maxiArea;
}

int main()
{
    return 0;
}