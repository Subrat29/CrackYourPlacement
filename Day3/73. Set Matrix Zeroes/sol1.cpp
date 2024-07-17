#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: m*n

void setZeroes(vector<vector<int>> &m)
{
    int row = m.size();
    int col = m[0].size();

    bool isFirstColZero = false;
    bool isFirstRowZero = false;

    // check the first row & col is zero or not

    // check row
    for (int i = 0; i < col; i++)
    {
        if (m[0][i] == 0)
            isFirstRowZero = true;
    }

    // check col
    for (int i = 0; i < row; i++)
    {
        if (m[i][0] == 0)
            isFirstColZero = true;
    }

    // Now, store the posn of zero in firstrow and firstcol
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (m[i][j] == 0)
            {
                m[0][j] = 0;
                m[i][0] = 0;
            }
        }
    }

    // Then, change the cell to zero acc to firstrow and firstcol value
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (m[i][0] == 0 || m[0][j] == 0)
            {
                m[i][j] = 0;
            }
        }
    }

    if (isFirstColZero)
    {
        for (int i = 0; i < row; i++)
        {
            m[i][0] = 0;
        }
    }

    if (isFirstRowZero)
    {
        for (int i = 0; i < col; i++)
        {
            m[0][i] = 0;
        }
    }
}

int main()
{
    return 0;
}