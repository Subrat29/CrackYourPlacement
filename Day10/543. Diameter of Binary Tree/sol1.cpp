#include <bits/stdc++.h>
using namespace std;

// sc: h = height of the tree
// tc: n = no of nodes

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int f(TreeNode *root, int &diameter)
{
    if (!root)
        return 0;

    int left = f(root->left, diameter);
    int right = f(root->right, diameter);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    // base case
    if (root == nullptr)
        return 0;

    int diameter = 0;
    f(root, diameter);
    return diameter;
}

int main()
{
    return 0;
}