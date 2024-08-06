#include <bits/stdc++.h>
using namespace std;

// sc: h
// tc: n

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;
    if (root1 && root2)
        root1->val += root2->val;

    if (root2->left)
        root1->left = mergeTrees(root1->left, root2->left);
    if (root2->right)
        root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

int main()
{
    return 0;
}