#include <bits/stdc++.h>
using namespace std;

// sc: n + k
// tc: nlogk (k = size of minHeap)

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // 1. store the freq of each elem in map
    unordered_map<int, int> mp;
    for (auto &&i : nums)
    {
        mp[i]++;
    }

    // 2. create a min heap
    auto cmp = [](pair<int, int> &lhs, pair<int, int> &rhs)
    {
        return lhs.second > rhs.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    // 3. push elem in minHeap
    for (auto &&i : mp)
    {
        pq.push(i);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    // 4. store top k freq elem in ans
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().first);
        pq.pop();
    }
    return ans;
}

int main()
{
    return 0;
}