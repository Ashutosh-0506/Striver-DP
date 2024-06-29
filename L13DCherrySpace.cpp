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
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev(m, vector<int>(m, 0));

        // initialise
        for (int col1 = 0; col1 < m; col1++)
        {
            for (int col2 = 0; col2 < m; col2++)
            {
                if (col1 == col2)
                {
                    prev[col1][col2] = grid[n - 1][col1];
                }
                else
                {
                    prev[col1][col2] = grid[n - 1][col1] + grid[n - 1][col2];
                }
            }
        }

        // DP
        for (int row = n - 2; row >= 0; row--)
        {
            vector<vector<int>> curr(m, vector<int>(m, 0));

            for (int col1 = m - 1; col1 >= 0; col1--)
            {
                for (int col2 = m - 1; col2 >= 0; col2--)
                {
                    int val = col1 == col2 ? (grid[row][col1]) : (grid[row][col1] + grid[row][col2]);
                    int maxx = -1e8;
                    for (int ncol1 = -1; ncol1 <= 1; ncol1++)
                    {
                        for (int ncol2 = -1; ncol2 <= 1; ncol2++)
                        {
                            if (col1 + ncol1 < m && col1 + ncol1 >= 0 && col2 + ncol2 < m && col2 + ncol2 >= 0)
                            {
                                maxx = max(maxx, prev[col1 + ncol1][col2 + ncol2]);
                            }
                        }
                    }
                    curr[col1][col2] = maxx + val;
                }
            }
            prev = curr;
        }
        // ans
        return prev[0][m - 1];
    }
};
int main()
{
    return 0;
}