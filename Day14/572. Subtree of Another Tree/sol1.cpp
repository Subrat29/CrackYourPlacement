#include <bits/stdc++.h>
using namespace std;

// tc: n*m (no of nodes in root, no of nodes in subRoot)
// sc: n+m

bool solve(TreeNode *root, TreeNode *subRoot)
{
    if (!root && !subRoot)
        return true;

    if (!root && subRoot)
        return false;
    if (root && !subRoot)
        return false;
    if (root->val != subRoot->val)
        return false;

    bool l = solve(root->left, subRoot->left);
    bool r = solve(root->right, subRoot->right);
    return l && r;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{

    if (!root)
        return false;

    if (solve(root, subRoot))
        return true;

    return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
}

int main()
{
    return 0;
}