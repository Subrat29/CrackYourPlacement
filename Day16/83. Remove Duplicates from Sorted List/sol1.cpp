#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr && temp->next != nullptr)
    {
        if (temp->val == temp->next->val)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    return head;
}

int main()
{
    return 0;
}