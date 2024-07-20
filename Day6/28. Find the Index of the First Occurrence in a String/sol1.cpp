#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

// Input: haystack = "sadbutsad", needle = "sad"

int strStr(string haystack, string needle)
{
    int j = 0;
    int n = needle.size();

    if (haystack == needle)
        return 0;

    for (int i = 0; i < haystack.length(); i++)
    {
        if (haystack[i] == needle[j])
        {
            j++;
            if (j == n)
            {
                cout << "i: " << i << "\n n : " << n << "\n abs: " << abs(i-n) << endl;
                return i - n + 1;
            }
        }
        else
            j = 0;
    }
    return -1;
}

int main()
{
    string haystack = "mississippi";
    string needle = "issip";
    cout << "Ans: " << strStr(haystack, needle);
    return 0;
}