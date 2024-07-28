#include <bits/stdc++.h>
using namespace std;

// tc: n
// sc: 1

int getDecimalValue(ListNode *head)
{
    int l = 0;
    ListNode *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }

    temp = head;
    int ans = 0;
    int x = pow(2, l);
    while (temp)
    {
        x /= 2;
        ans += x * temp->val;
        temp = temp->next;
    }
    return ans;
}

int main()
{
    return 0;
}