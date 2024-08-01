#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode* reverseHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reverseHead;
}

int main()
{
    return 0;
}