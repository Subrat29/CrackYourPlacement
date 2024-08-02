#include <bits/stdc++.h>
using namespace std;

// sc: v + e
// tc: n

bool solve(int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[])
{
    vis[node] = 1;
    dfsVis[node] = 1; // Corrected from dfs[node] to dfsVis[node]

    for (auto &&nbr : adj[node])
    {
        if (!vis[nbr])
        {
            if (solve(nbr, vis, dfsVis, adj)) // Changed dfs to solve
                return true;
        }
        else if (dfsVis[nbr])
            return true;
    }
    // Never forget this backtrack
    dfsVis[node] = 0; // Changed from dfsVis[node] = 1 to dfsVis[node] = 0 for backtracking
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> vis(V, 0);
    vector<bool> dfsVis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (solve(i, vis, dfsVis, adj)) // Changed dfs to solve
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}