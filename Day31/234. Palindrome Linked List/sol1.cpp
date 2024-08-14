#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

bool isPalindrome(ListNode *head)
{
    // Find Middle of the List
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *prev = nullptr;
    while (slow)
    {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // Now, check is it palindrome or not?
    slow = head;
    fast = prev;
    while (fast)
    {
        if (slow->val != fast->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

int main()
{
    return 0;
}