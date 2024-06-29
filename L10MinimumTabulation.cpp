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
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                {
                    dp[row][col] = grid[row][col];
                }
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if (row > 0)
                    {
                        up = dp[row - 1][col];
                    }
                    if (col > 0)
                    {
                        left = dp[row][col - 1];
                    }
                    dp[row][col] = grid[row][col] + min(up, left);
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