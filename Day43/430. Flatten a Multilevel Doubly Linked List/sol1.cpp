#include <bits/stdc++.h>
using namespace std;

// tc:
// sc:

Node *flatten(Node *head)
{
    for (Node *h = head; h; h = h->next)
    {
        if (h->child)
        {
            Node *next = h->next;
            h->next = h->child;
            h->next->prev = h;
            h->child = NULL;
            Node *p = h->next;
            while (p->next)
                p = p->next;
            p->next = next;
            if (next)
                next->prev = p;
        }
    }
    return head;
}

int main()
{
    return 0;
}