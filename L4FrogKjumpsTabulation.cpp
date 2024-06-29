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
// Main function to minimize the cost using dynamic programming
int minimizeCost(int n, int k, vector<int> &height)
{
    // Initialize a memoization array with -1 and set the cost at index 0 to 0
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    // Iterate through each index starting from 1
    for (int i = 1; i < n; i++)
    {
        // Initialize steps to a large value
        int steps = INT_MAX;

        // Iterate through possible steps from 1 to k
        for (int j = 1; j <= k; j++)
        {
            // Check if stepping back by j is a valid index
            if (i - j >= 0)
            {
                // Calculate the cost for the current step and use the previously computed result from dp array
                steps = min(steps, abs(height[i] - height[i - j]) + dp[i - j]);
            }
        }

        // Store the minimum cost at the current index in the dp array
        dp[i] = steps;
    }

    // The result is the minimum cost to reach the last index (n-1)
    return dp[n - 1];
}
