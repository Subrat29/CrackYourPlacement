#include <bits/stdc++.h>
using namespace std;

// tc: v + e
// sc: v

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        for (auto &&nbr : adj[frontNode])
        {
            if (visited[nbr] == false)
            {
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}