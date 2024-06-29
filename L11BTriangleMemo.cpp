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
    int solve(int step, int index, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (step == n - 1)
        {
            return triangle[step][index];
        }
        if (dp[step][index] != -1)
        {
            return dp[step][index];
        }
        int minn = INT_MAX;

        // Same
        minn = min(minn, solve(step + 1, index, n, triangle, dp));
        // Next
        minn = min(minn, solve(step + 1, index + 1, n, triangle, dp));

        return dp[step][index] = triangle[step][index] + minn;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int index = 0;
        int step = 0;
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(step, index, n, triangle, dp);
    }
};
int main()
{
    return 0;
}