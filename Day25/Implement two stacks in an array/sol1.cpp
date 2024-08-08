#include <bits/stdc++.h>
using namespace std;

// sc:
// tc:

class twoStacks
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    twoStacks(int s)
    {
        this->size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size - 1;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        if (top1 >= size - 1 || (top2 - top1) <= 1)
        {
            cout << "Stack1 Overflow!!! " << endl;
        }
        else
        {

            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        if (top2 == 0 || (top2 - top1) <= 1)
        {
            cout << "Stack2 overflow!!! " << endl;
        }
        else
        {

            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        if (top1 == -1)
        {
            // cout<<"Stack1 Underflow!!!"<<endl;
            return -1;
        }

        return arr[top1--];
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        if (top2 == size - 1)
        {
            // cout<<"Stack2 underflow!!!"<<endl;
            return -1;
        }

        return arr[top2++];
    }
};

int main()
{
    return 0;
}