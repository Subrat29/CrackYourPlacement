#include <bits/stdc++.h>
using namespace std;

// tc: sLen + tLen
// sc: tLen

string minWindow(string s, string t)
{
    int tLen = t.length();
    int sLen = s.length();

    if (sLen < tLen)
        return "";

    unordered_map<char, int> mp;
    for (char c : t)
        mp[c]++;

    int cnt = 0;          
    int minLen = INT_MAX; 
    int startIdx = 0;     
    int left = 0;

    for (int right = 0; right < sLen; right++)
    {
        if (mp.find(s[right]) != mp.end())
        {               
            mp[s[right]]--;
            if (mp[s[right]] >= 0)
                cnt++;
        }

        // When all characters of t are matched
        while (cnt == tLen)
        {
            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                startIdx = left;
            }

            if (mp.find(s[left]) != mp.end())
            {
                mp[s[left]]++;
                if (mp[s[left]] > 0) // if mp['s'] == 1, means abhi ek s chahiye thats why cnt dec kr do
                    cnt--;
            }
            left++;
        }
    }

    // Return the minimum window or an empty string if no valid window is found
    return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
}

int main()
{
    return 0;
}