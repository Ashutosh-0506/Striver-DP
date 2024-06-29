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
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int index = 0;
        int step = 0;
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int step = n - 2; step >= 0; step--)
        {
            for (int index = step; index >= 0; index--)
            {

                int minn = INT_MAX;
                // Same
                minn = min(minn, dp[step + 1][index]);
                // Next
                minn = min(minn, dp[step + 1][index + 1]);

                dp[step][index] = triangle[step][index] + minn;
            }
        }
        return dp[0][0];
    }
};
int main()
{
    return 0;
}