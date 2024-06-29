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
    // Recursive Solution
    int climbStairsRecursive(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
    }

    // Memoization Solution
    int climbStairsMemoization(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }

    int solve(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    // Tabulation Solution
    int climbStairsTabulation(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Space Optimization Solution
    int climbStairsSpaceOptimization(int n)
    {
        int prev2 = 1;
        int prev = 1;
        for (int i = 2; i <= n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}; 
int main()
{
    return 0;
}