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
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int minn = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = n - 1; col >= 0; col--)
            {
                int prev = INT_MAX;
                int same = INT_MAX;
                int next = INT_MAX;
                if (col - 1 >= 0)
                {
                    prev = dp[row + 1][col - 1];
                }
                same = dp[row + 1][col];
                if (col + 1 < n)
                {
                    next = dp[row + 1][col + 1];
                }
                dp[row][col] = min(same, min(prev, next)) + matrix[row][col];
            }
        }
        for (int i = 0; i < n; i++)
        {
            minn = min(minn, dp[0][i]);
        }
        return minn;
    }
};
int main()
{
    return 0;
}