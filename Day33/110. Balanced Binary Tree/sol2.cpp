#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: n

int solve(TreeNode *root)
{
    if (!root)
        return 0;
    int lh = solve(root->left);
    int rh = solve(root->right);
    if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
    {
        return -1;
    }
    return 1 + max(lh, rh);
}
bool isBalanced(TreeNode *root)
{
    return solve(root) != -1;
}

int main()
{
    return 0;
}