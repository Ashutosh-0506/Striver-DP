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

//Memoiation

// Recursive function to calculate the maximum sum of non-adjacent elements
int solve(int index, vector<int> &nums, vector<int> &dp)
{
    // Base case: If there's only one element, return its value
    if (index == 0)
    {
        return nums[index];
    }

    // Base case: If the index is negative, return 0 (no more elements to consider)
    if (index < 0)
    {
        return 0;
    }

    // Check if the result for the current state is already memoized
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // Calculate the maximum sum by either picking the current element
    // and skipping the previous element, or not picking the current element
    int pick = nums[index] + solve(index - 2, nums, dp);
    int notpick = solve(index - 1, nums, dp);

    // Memoize the result for the current state and return it
    return dp[index] = max(pick, notpick);
}

// Function to find the maximum sum of non-adjacent elements in a vector
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int index = n - 1;
    vector<int> dp(n, -1); // Memoization table to store results of subproblems
    return solve(index, nums, dp); // Call the recursive function with memoization
}

int main()
{
    return 0;
}