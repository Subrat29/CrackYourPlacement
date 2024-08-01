#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)

int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    while (s <= e) // Changed to <= to include the end index
    {
        int mid = s + (e - s) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1]))
        {
            return mid;
        }
        // Move right if the element on the right is greater
        else if (mid > 0 && nums[mid - 1] > nums[mid])
        {
            e = mid - 1;
        }
        // Move left if the element on the left is greater
        else
        {
            s = mid + 1;
        }
    }

    return -1; // This should never be reached
}

int main()
{
    return 0;
}
