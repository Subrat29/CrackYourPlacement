#include <bits/stdc++.h>
using namespace std;

// sc: textLength - patternLength + 1
// tc: (textLength - patternLength + 1)*patternLength

vector<int> search(string pattern, string text)
{
    vector<int> indices;

    int textLength = text.length();
    int patternLength = pattern.length();

    // Loop through the text to find matches
    for (int i = 0; i <= textLength - patternLength; ++i)
    {
        if (text.substr(i, patternLength) == pattern)
            indices.push_back(i + 1); // Adjust index to be 1-based
    }

    return indices;
}

int main()
{
    return 0;
}