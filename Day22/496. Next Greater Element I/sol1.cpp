#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// tc : n1 + n2
// sc : n1 + n2

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    stack<int> s;
    unordered_map<int, int> nextGreater;

    // Initialize next greater elements for nums2
    for (int i = n2 - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop(); // Pop elements from stack until we find a greater element
        }
        nextGreater[nums2[i]] = s.empty() ? -1 : s.top(); // Use -1 if no greater element is found
        s.push(nums2[i]);                                 // Push the current element onto the stack
    }

    // Prepare the answer based on nums1
    vector<int> ans(n1);
    for (int i = 0; i < n1; i++)
    {
        ans[i] = nextGreater[nums1[i]]; // Lookup next greater element from the hashmap
    }

    return ans;
}

int main()
{
    return 0;
}
