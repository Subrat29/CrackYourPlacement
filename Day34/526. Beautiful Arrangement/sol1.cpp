#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

void dfs(vector<int> v, int index, int &ans)
{
    if (index == v.size())
    {
        ans++;
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        if (v[i] % (index + 1) == 0 || (index + 1) % v[i] == 0)
        {
            swap(v[i], v[index]);
            dfs(v, index + 1, ans);
            swap(v[i], v[index]);
        }
    }
}

int countArrangement(int N)
{
    vector<int> v;
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        v.push_back(i);
    }
    dfs(v, 0, ans);
    return ans;
}

int main()
{
    return 0;
}