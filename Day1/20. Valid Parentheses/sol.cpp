#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

bool isValid(string s)
{
    int i = -1;
    for (auto &&c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            s[++i] = c;
        else if (i >= 0 && ((s[i] == '(' && c == ')') || (s[i] == '[' && c == ']') || (s[i] == '{' && c == '}')))
            i--;
        else
            return false;
    }
    if (i == -1)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}