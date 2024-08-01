#include <bits/stdc++.h>
using namespace std;

// sc: V
// tc: V + E

bool dfs(int node, int parent, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = 1;

    for (auto &&nbr : adj[node])
    {
        if (!vis[nbr])
        {
            if (dfs(nbr, node, vis, adj))
                return true;
        }
        else if (nbr != parent)
            return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            if (dfs(i, -1, vis, adj))
                return true;
    }
    return false;
}

int main()
{
    return 0;
}