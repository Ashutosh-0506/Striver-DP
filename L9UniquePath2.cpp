//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace ::std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    dp[0][0] = 1;
                }
                else
                {
                    int up = 0;
                    int left = 0;
                    if (row > 0 && obstacleGrid[row][col] == 0)
                    {
                        up += dp[row - 1][col];
                    }
                    if (col > 0 && obstacleGrid[row][col] == 0)
                    {
                        left += dp[row][col - 1];
                    }
                    dp[row][col] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};  
int main()
{
    return 0;
}