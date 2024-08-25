#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

bool solve(Node *root, int mini, int maxi)
{
    if (root == nullptr)
        return false;

    if (root->left == nullptr && root->right == nullptr)
    {
        if (mini == maxi)
            return true;
        else
            return false;
    }

    return solve(root->left, mini, min(root->data - 1, maxi)) || solve(root->right, max(root->data + 1, mini), maxi);
}

bool isDeadEnd(Node *root)
{
    int mini = 1;
    int maxi = INT_MAX;
    return solve(root, mini, maxi);
}

int main()
{
    return 0;
}