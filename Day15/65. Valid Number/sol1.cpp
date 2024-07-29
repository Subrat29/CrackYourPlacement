#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

bool isNumber(string s)
{
    bool number_seen = false;
    bool point_seen = false;
    bool e_seen = false;

    for (int i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            number_seen = true;
        }
        else if (s[i] == '.')
        {
            if (point_seen || e_seen)
                return false;
            point_seen = true;
        }
        else if (s[i] == 'e' || s[i] == 'E')
        {
            if (!number_seen || e_seen)
                return false;
            e_seen = true;
            number_seen = false;
        }
        else if (s[i] == '-' || s[i] == '+')
        {
            if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                return false;
        }
        else
        {
            return false;
        }
    }
    return number_seen;
}

int main()
{
    return 0;
}