#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

void solve(TreeNode *&root, string s, vector<string> &ans)
{
    if (root->left == nullptr && root->right == nullptr)
        return ans.push_back(s + to_string(root->val));

    if (root->left)
        solve(root->left, s + to_string(root->val) + "->", ans);

    if (root->right)
        solve(root->right, s + to_string(root->val) + "->", ans);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    if (root)
        solve(root, "", ans);
    return ans;
}

int main()
{
    return 0;
}