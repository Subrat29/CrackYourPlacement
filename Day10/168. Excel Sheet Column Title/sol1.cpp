#include <bits/stdc++.h>
using namespace std;

// sc: log base26 (n)
// tc: log base26 (n)

string convertToTitle(int columnNumber)
{
    string ans = "";
    while (columnNumber)
    {
        columnNumber--; // For edge case if col is multiple of 26
        int rem = columnNumber % 26;
        ans += 'A' + rem;
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Input: columnNumber = 28
// Output: "AB"

int main()
{
    return 0;
}