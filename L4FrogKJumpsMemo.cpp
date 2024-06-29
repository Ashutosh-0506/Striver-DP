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

// Helper function to solve the problem using dynamic programming
int solve(int index, int n, int k, vector<int> &height, vector<int> &dp)
{
    // Base case: if the index is 0, we have reached the starting point, and cost is 0
    if (index == 0)
    {
        return 0;
    }

    // If the solution for the current index is already calculated, return it
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // Initialize steps to a large value
    int steps = INT_MAX;

    // Iterate through possible steps from 1 to k
    for (int i = 1; i <= k; i++)
    {
        // Check if stepping back by i is a valid index
        if (index - i >= 0)
        {
            // Calculate the cost for the current step and recursively solve for the remaining steps
            steps = min(steps, abs(height[index] - height[index - i]) + solve(index - i, n, k, height, dp));
        }
    }

    // Memoize the result and return
    return dp[index] = steps;
}

// Main function to minimize the cost
int minimizeCost(int n, int k, vector<int> &height)
{
    // Initialize a memoization array with -1
    vector<int> dp(n + 1, -1);

    // Start from the second-to-last index (n-1) and solve the problem
    int index = n - 1;
    return solve(index, n, k, height, dp);
}

int main()
{
    return 0;
}