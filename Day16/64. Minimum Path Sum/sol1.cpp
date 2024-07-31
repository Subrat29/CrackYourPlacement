#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// tc: m*n
// sc: m*n

// bottom to up
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> next(n, 0);
    vector<int> curr(n, 0);
    next[n - 1] = grid[m - 1][n - 1];

    // fill last row
    for (int i = n - 2; i >= 0; i--)
        next[i] = next[i + 1] + grid[m - 1][i];

    // Fill the rest of the rows from bottom to top
    for (int i = m - 2; i >= 0; i--)
    {
        // Update the last cell of the current row
        curr[n - 1] = next[n - 1] + grid[i][n - 1];
        for (int j = n - 2; j >= 0; j--)
        {
            curr[j] = grid[i][j] + min(curr[j + 1], next[j]);
        }
        swap(next, curr);
    }
    return next[0];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum Path Sum: " << minPathSum(grid) << endl;
    return 0;
}
