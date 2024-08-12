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
class BSTIterator
{
private:
    queue<int> v;
    void inorder(TreeNode *root, queue<int> &v)
    {
        if (root == nullptr)
            return;

        inorder(root->left, v);
        v.push(root->val);
        inorder(root->right, v);
    }

public:
    BSTIterator(TreeNode *root)
    {
        inorder(root, v);
    }

    int next()
    {
        int num = v.front();
        v.pop();
        return num;
    }

    bool hasNext()
    {
        return !v.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    return 0;
}