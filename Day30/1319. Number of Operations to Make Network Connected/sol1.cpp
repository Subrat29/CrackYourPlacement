#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[i] = true;
    for (auto &&neighbor : adj[i])
    {
        if (!visited[neighbor])
            dfs(neighbor, visited, adj);
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;

    // adj list
    vector<vector<int>> adj(n);
    for (auto &&connection : connections)
    {
        int u = connection[0];
        int v = connection[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
            cnt++;
        }
    }
    return cnt - 1;
}

int main()
{
    return 0;
}