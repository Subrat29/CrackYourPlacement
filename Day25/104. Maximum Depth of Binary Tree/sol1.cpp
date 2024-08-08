#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
}

int main()
{
    return 0;
}