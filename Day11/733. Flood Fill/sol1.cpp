#include <bits/stdc++.h>
using namespace std;

// sc: m*n
// tc: m*n

void dfs(vector<vector<int>> &image, int i, int j, int presentColor, int newColor)
{
    if (i < 0 || i == image.size() || j < 0 || j == image[0].size() || image[i][j] != presentColor)
        return;

    image[i][j] = newColor;
    dfs(image, i + 1, j, presentColor, newColor);
    dfs(image, i, j + 1, presentColor, newColor);
    dfs(image, i - 1, j, presentColor, newColor);
    dfs(image, i, j - 1, presentColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int presentColor = image[sr][sc];

    // Check first to present infinite loops when the present and new colors are same
    if (presentColor != color)
        dfs(image, sr, sc, presentColor, color);
    return image;
}

int main()
{
    return 0;
}