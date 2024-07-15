#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

ListNode *middleNode(ListNode *head)
{

    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}