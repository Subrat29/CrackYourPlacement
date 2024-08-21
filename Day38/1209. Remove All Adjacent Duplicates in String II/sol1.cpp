#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        // dummy pair to avoid empty stack
        vector<pair<int, int>> stack = {{0, '#'}};

        for (char c : s)
        {
            if (c != stack.back().second)
            {
                stack.push_back({1, c});
            }
            else
            {
                stack.back().first++;
                if (stack.back().first == k)
                    stack.pop_back();
            }
        }

        string res;
        for (auto &p : stack)
        {
            res.append(p.first, p.second);
        }
        return res;
    }
};

int main()
{
    return 0;
}