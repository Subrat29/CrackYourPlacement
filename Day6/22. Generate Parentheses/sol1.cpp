#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        addParanthesis(ans, "", n, 0);
        return ans;
    }

    void addParanthesis(vector<string> &ans, string s, int n, int m)
    {
        if (n == 0 && m == 0)
        {
            ans.push_back(s);
            return;
        }

        if (m > 0)
        {
            addParanthesis(ans, s + ")", n, m - 1);
        }
        if (n > 0)
        {
            addParanthesis(ans, s + "(", n - 1, m + 1);
        }
    }
};

int main()
{
    return 0;
}