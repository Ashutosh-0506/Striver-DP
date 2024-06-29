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

// Function to calculate the maximum sum of non-adjacent elements in a vector
long long int solve(vector<int> &nums)
{
    long long int n = nums.size();
    long long int prev = 0;
    long long int prev2 = 0;
    prev = nums[0];

    // Loop through the array to calculate the maximum sum for each index
    for (long long int i = 1; i < n; i++)
    {
        long long int take = nums[i];

        // If the current index is greater than 1, add the maximum sum from two indices ago
        if (i > 1)
        {
            take += prev2;
        }

        long long int nottake = prev;  // Skip the current element

        // Choose the maximum between taking and not taking the current element
        long long int curr = max(take, nottake);

        // Update 'prev2' and 'prev' for the next iteration
        prev2 = prev;
        prev = curr;
    }

    // The final result is stored in 'prev', which represents the maximum sum of non-adjacent elements
    return prev;
}

// Function to solve the house robbery problem
long long int houseRobber(vector<int> &valueInHouse)
{
    long long int n = valueInHouse.size();

    // Base case: If there is only one house, return its value
    if (n == 1)
    {
        return valueInHouse[0];
    }

    // Create two vectors 'a' and 'b' to represent two cases:
    // Case 1: Rob the first house, skip the last house
    // Case 2: Skip the first house, rob the last house
    vector<int> a, b;
    for (long long int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            a.push_back(valueInHouse[i]);
        }
        if (i != n - 1)
        {
            b.push_back(valueInHouse[i]);
        }
    }

    // Calculate the maximum sum for each case using the 'solve' function
    long long int ans1 = solve(a);
    long long int ans2 = solve(b);

    // Return the maximum sum between the two cases
    return max(ans1, ans2);
}

int main()
{
    return 0;
}