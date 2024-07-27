#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> q; // maxHeap

    for (int i : nums)
        q.push(i);

    for (int i = 1; i < k; i++)
        q.pop();

    return q.top();
}

int main()
{
    return 0;
}