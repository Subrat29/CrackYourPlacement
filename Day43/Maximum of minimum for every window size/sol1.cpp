#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class Solution
{
public:
    // Function to find maximum of minimums of every window size.

    vector<int> prevSmaller(int arr[], int n)
    {
        vector<int> left(n, -1);

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }

    vector<int> nextSmaller(int arr[], int n)
    {
        vector<int> right(n, n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }

    vector<int> maxOfMin(int arr[], int n)
    {
        // Your code here

        vector<int> left = prevSmaller(arr, n);
        vector<int> right = nextSmaller(arr, n);

        int mini = arr[0];
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
        }

        vector<int> ans(n + 1, 0);

        // Fill ans[] by comparing the maximum for each window size
        for (int i = 0; i < n; i++)
        {
            int len = right[i] - left[i] - 1;
            ans[len] = max(ans[len], arr[i]);
        }

        // Fill the rest of the ans array
        for (int i = n - 1; i >= 1; i--)
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        ans.erase(ans.begin()); // Remove the first element which is not used

        return ans;
    }
};

int main()
{
    return 0;
}