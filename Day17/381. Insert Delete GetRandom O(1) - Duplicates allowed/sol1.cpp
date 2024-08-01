#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

class RandomizedCollection
{
public:
    RandomizedCollection()
    {
        unordered_map<int, int> mp;
        vector<int> arr;
    }

    bool insert(int val)
    {
        bool isValPresent = mp[val] == 0;
        mp[val]++;
        arr.push_back(val);
        return !isValPresent;
    }

    bool remove(int val)
    {
        if (mp[val] == 0)
        {
            return false;
        }
        else
        {
            mp[val]--;

            // Remove value from array
            auto it = find(arr.begin(), arr.end(), val);
            if (it != end())
                arr.erase(it);

            return true;
        }
    }

    int getRandom()
    {
        int n = arr.size();
        return arr[rand() % n];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{
    return 0;
}