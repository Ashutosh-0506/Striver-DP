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

//Tabulation

// Function to find the maximum sum of non-adjacent elements in a vector
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1); // Memoization table to store results of subproblems

    // Base case: The maximum sum for the first element is the value of the first element itself
    dp[0] = nums[0];

    // Loop through the array to calculate the maximum sum for each index
    for (int i = 1; i < n; i++)
    {
        int take = nums[i]; // Consider the current element

        // If the current index is greater than 1, add the maximum sum from two indices ago
        if (i > 1)
        {
            take += dp[i - 2];
        }

        int nottake = dp[i - 1]; // Skip the current element

        // Choose the maximum between taking and not taking the current element
        dp[i] = max(take, nottake);
    }

    // The final result is the maximum sum for the last element in the vector
    return dp[n - 1];
}

int main()
{
    return 0;
}