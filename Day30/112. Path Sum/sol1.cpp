#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
    {
        return false;
    }

    if (!root->left && !root->right)
    {
        return targetSum == root->val;
    }

    bool left_sum = hasPathSum(root->left, targetSum - root->val);
    bool right_sum = hasPathSum(root->right, targetSum - root->val);

    return left_sum || right_sum;
}

int main()
{
    return 0;
}