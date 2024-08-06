#include <bits/stdc++.h>
using namespace std;

// sc: n
// tc: n

int evaluatePostfix(string S)
{
    stack<int> st;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '*' || S[i] == '/' || S[i] == '+' || S[i] == '-')
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if (S[i] == '*')
                st.push(a * b);
            else if (S[i] == '-')
                st.push(a - b);
            else if (S[i] == '+')
                st.push(a + b);
            else
                st.push(a / b);
        }
        else
        {
            st.push(S[i] - '0');
        }
    }
    return st.top();
}

int main()
{
    return 0;
}