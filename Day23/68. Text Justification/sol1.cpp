#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * k)
// Space Complexity: O(n * L)
// where n is the number of words,
// k is the maximum number of words that can fit in a line,
// L is the average length of the words.

string justify(int start, int end, int eachWordSpace, int extraSpace, int &maxWidth, vector<string> &words)
{
    string line = "";

    for (int i = start; i < end; i++)
    {
        line += words[i];

        if (i == end - 1)
            continue;

        for (int j = 0; j < eachWordSpace; j++)
        {
            line += " ";
        }

        if (extraSpace > 0)
        {
            line += " ";
            extraSpace--;
        }
    }

    while (line.length() < maxWidth)
    {
        line += " ";
    }
    return line;
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> ans;
    int n = words.size();
    int i = 0;
    while (i < n)
    {
        int lettersCount = words[i].length();
        int middleSpace = 0;
        int j = i + 1;

        // Fill the line until maxWidth
        while (j < n && middleSpace + lettersCount + words[j].length() + 1 <= maxWidth)
        {
            lettersCount += words[j].length();
            middleSpace++;
            j++;
        }

        // Now, Justify this line
        int remainingSlots = maxWidth - lettersCount;
        int eachWordSpace = middleSpace == 0 ? 0 : remainingSlots / middleSpace;
        int extraSpace = middleSpace == 0 ? 0 : remainingSlots % middleSpace;

        // Last line should be left justified
        if (j == n)
        {
            eachWordSpace = 1;
            extraSpace = 0;
        }

        string justifiedLine = justify(i, j, eachWordSpace, extraSpace, maxWidth, words);
        ans.push_back(justifiedLine);
        i = j;
    }
    return ans;
}

int main()
{
    return 0;
}