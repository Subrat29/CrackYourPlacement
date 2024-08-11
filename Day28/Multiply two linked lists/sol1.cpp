#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
#define mod 1000000007
long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long a = 0, b = 0;

    while (l1 != NULL)
    {
        a = (a * 10 + l1->data) % mod;
        l1 = l1->next;
    }

    while (l2 != NULL)
    {
        b = (b * 10 + l2->data) % mod;
        l2 = l2->next;
    }

    return (a * b) % mod;
}

int main()
{
    return 0;
}