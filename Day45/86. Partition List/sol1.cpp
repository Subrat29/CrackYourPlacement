#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

ListNode *partition(ListNode *head, int x)
{
    ListNode *dummy1 = new ListNode();
    ListNode *temp1 = dummy1;
    ListNode *dummy2 = new ListNode();
    ListNode *temp2 = dummy2;
    while (head != NULL)
    {
        if (head->val < x)
        {
            temp1->next = head;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = head;
            temp2 = temp2->next;
        }
        head = head->next;
    }
    if (dummy1->next == NULL)
        return dummy2->next;
    temp1->next = dummy2->next;
    temp2->next = NULL;
    return dummy1->next;
}

int main()
{
    return 0;
}