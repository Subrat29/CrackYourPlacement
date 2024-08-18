#include <bits/stdc++.h>
using namespace std;

// tc: 2n
// sc: n

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    Node *temp = head;
    map<Node *, Node *> m;

    while (temp)
    {
        m[temp] = new Node(temp->val);
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        Node *copyNode = m[temp];
        copyNode->next = m[temp->next];
        copyNode->random = m[temp->random];
        temp = temp->next;
    }
    return m[head];
}

int main()
{
    return 0;
}