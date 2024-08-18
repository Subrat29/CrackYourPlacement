#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *rev(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *nxt = NULL;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;

            curr = nxt;
        }

        return prev;
    }

    Node *compute(Node *head)
    {
        // your code goes here
        head = rev(head);
        int cMax = head->data;
        Node *prev = NULL;
        Node *curr = head;

        while (curr)
        {
            if (curr->data >= cMax)
            {
                // keep
                cMax = curr->data;
                prev = curr;
                curr = curr->next;
            }
            else
            {
                // delete
                curr = curr->next;
                delete (prev->next);
                prev->next = curr;
            }
        }

        head = rev(head);
        return head;
    }
};

int main()
{
    return 0;
}