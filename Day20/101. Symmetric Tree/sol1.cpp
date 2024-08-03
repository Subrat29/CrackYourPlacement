#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool solve(TreeNode *leftTree, TreeNode *rightTree)
{
    if (!leftTree && !rightTree)
        return true;
    else if (!leftTree && right)
        return false;
    else if (leftTree && !rightTree)
        return false;
    else if (leftTree->val != rightTree->val)
        return false;

    return solve(leftTree->left, rightTree->right) && solve(leftTree->right, rightTree->left);
}

bool isSymmetric(TreeNode *root)
{
    return solve(root->left, root->right);
}

int main()
{
    return 0;
}