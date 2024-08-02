#include <bits/stdc++.h>
using namespace std;

// sc: h
// tc: n

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == nullptr)
        return 0;

    int totSum = 0;

    if (root->val >= low && root->val <= high)
        totSum += root->val;

    if (root->val >= low)
        totSum += rangeSumBST(root->left, low, high);

    if (root->val <= high)
        totSum += rangeSumBST(root->right, low, high);

    return totSum;
}

int main()
{
    return 0;
}