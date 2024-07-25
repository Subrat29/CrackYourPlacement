#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

string reverseWords(string s)
{
    // 1. reverse input string
    reverse(s.begin(), s.end());

    int n = s.length();
    int subStrStart = 0;
    int subStrEnd = 0;

    for (int i = 0; i < n; i++)
    {
        // 2. Remove the front spaces
        while (i < n && s[i] != ' ')
        {
            s[subStrEnd] = s[i];
            subStrEnd++;
            i++;
        }

        if (subStrEnd > subStrStart)
        {
            // 3. Convert it to original word which we reverse in step 1
            reverse(s.begin() + subStrStart, s.begin() + subStrEnd);

            // 4. If we reach to end of input string then get out from loop
            if (subStrEnd == n)
                break;

            // 5. Else add a space to separate the words
            s[subStrEnd] = ' ';
            subStrEnd++;

            // 6. Also, reinitialize substring pointers after each word
            subStrStart = subStrEnd;
        }
    }

    // 7. There is no need to add space if we reach to end
    if (subStrStart > 0 && s[subStrEnd - 1] == ' ')
        subStrEnd--;

    s.resize(subStrEnd);
    return s;
}

int main()
{
    string str = "  hello world  ";
    string s = reverseWords(str);

    cout << str << endl;
    cout << s << endl;
    return 0;
}