#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: n

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *nxt = head->next;

    while (curr)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (nxt)
            nxt = nxt->next;
    }
    return prev;
}

int main()
{
    return 0;
}