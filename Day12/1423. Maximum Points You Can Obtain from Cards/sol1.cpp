#include <bits/stdc++.h>
using namespace std;

// sc: 1
// tc: 2*k

int maxScore(vector<int> &cardPoints, int k)
{
    int maxScore = 0;
    int rightSum = 0;
    int leftSum = 0;

    for (int i = 0; i < k; i++)
        leftSum += cardPoints[i];
    maxScore = leftSum;

    int rightIdx = cardPoints.size() - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        leftSum -= cardPoints[i];
        rightSum += cardPoints[rightIdx];
        rightIdx--;
        maxScore = max(maxScore, leftSum + rightSum);
    }
    return maxScore;
}

int main()
{
    return 0;
}