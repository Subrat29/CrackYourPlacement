#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: 1

// dq : deque in which element is to be pushed
// x : element to be pushed

// Function to push element x to the back of the deque.
void push_back_pb(deque<int> &dq, int x)
{
    dq.push_back(x);
}

// Function to pop element from back of the deque.
void pop_back_ppb(deque<int> &dq)
{
    if (!dq.empty())
        dq.pop_back();
    else
        return;
}

// Function to return element from front of the deque.
int front_dq(deque<int> &dq)
{
    if (!dq.empty())
        return dq.front();
    else
        return -1;
}

// Function to push element x to the front of the deque.
void push_front_pf(deque<int> &dq, int x)
{
    dq.push_front(x);
}

int main()
{
    return 0;
}