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
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
        {
            return grid[0][0];
        }
        if (row < 0 || col < 0)
        {
            return INT_MAX;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int up = solve(row - 1, col, grid, dp);
        int left = solve(row, col - 1, grid, dp);
        return dp[row][col] = grid[row][col] + min(up, left);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, grid, dp);
    }
};
int main()
{
    return 0;
}