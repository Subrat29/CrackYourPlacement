#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

class Trie
{
public:
    Trie()
    {
        // Initialization of the Trie
    }
    void insert(std::string word)
    {
        std::string cur = "";
        for (char c : word)
        {
            cur += c;
            prefs.insert(cur);
        }
        data.insert(word);
    }

    bool search(std::string word)
    {
        return data.find(word) != data.end();
    }

    bool startsWith(std::string prefix)
    {
        return prefs.find(prefix) != prefs.end();
    }

private:
    std::unordered_set<std::string> data;
    std::unordered_set<std::string> prefs;
};

int main()
{
    return 0;
}