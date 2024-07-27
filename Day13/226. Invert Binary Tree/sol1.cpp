#include <bits/stdc++.h>
using namespace std;

// sc: h
// tc: n

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;

    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main()
{
    return 0;
}