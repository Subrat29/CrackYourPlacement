#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

vector<vector<int>> kClosest(vector<vector<int>> &P, int k)
{
    auto euclidean = [](auto &p)
    { return p[0] * p[0] + p[1] * p[1]; };
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < P.size(); i++)
    {
        pq.emplace(euclidean(P[i]), i);
        if (pq.size() > k)
            pq.pop();
    }
    vector<vector<int>> ans(k);
    for (int i = 0; i < k; i++)
        ans[i] = P[pq.top().second], pq.pop();

    return ans;
}

int main()
{
    return 0;
}