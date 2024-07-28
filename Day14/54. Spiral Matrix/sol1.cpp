#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int totalCell = row * col;

    int s_row = 0;
    int e_row = row - 1;
    int s_col = 0;
    int e_col = col - 1;

    vector<int> ans;
    int cnt = 0;
    while (cnt < totalCell)
    {
        // first row
        for (int i = s_col; cnt < totalCell && i <= e_col; i++)
        {
            ans.push_back(matrix[s_row][i]);
            cnt++;
        }
        s_row++;

        // last col
        for (int i = s_row; cnt < totalCell && i <= e_row; i++)
        {
            ans.push_back(matrix[i][e_col]);
            cnt++;
        }
        e_col--;

        // last row
        for (int i = e_col; cnt < totalCell && i >= s_col; i--)
        {
            ans.push_back(matrix[e_row][i]);
            cnt++;
        }
        e_row--;

        // first col
        for (int i = e_row; cnt < totalCell && i >= s_row; i--)
        {
            ans.push_back(matrix[i][s_col]);
            cnt++;
        }
        s_col++;
    }
    return ans;
}

int main()
{
    return 0;
}