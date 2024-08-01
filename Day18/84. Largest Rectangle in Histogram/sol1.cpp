#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

// Remember: Actually, we are storing the index in nextSmaller and prevSmaller vectors not values.

vector<int> findNextSmaller(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && arr[i] <= arr[s.top()])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> findPrevSmaller(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && arr[i] <= arr[s.top()])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> nextSmaller;
    nextSmaller = findNextSmaller(heights, n);

    vector<int> prevSmaller;
    prevSmaller = findPrevSmaller(heights, n);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (nextSmaller[i] == -1)
            nextSmaller[i] = n;

        int b = nextSmaller[i] - prevSmaller[i] - 1;

        maxArea = max(maxArea, l * b);
    }
    return maxArea;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    vector<int> nextSmaller;
    nextSmaller = findNextSmaller(heights, 6);

    for (auto &&i : nextSmaller)
        cout << i << " ";

    return 0;
}