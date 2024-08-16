#include <bits/stdc++.h>
using namespace std;

// tc: n^2
// sc: n

int height(TreeNode *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    return 0;
}