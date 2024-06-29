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


//Space Optimization

// Function to find the maximum sum of non-adjacent elements in a vector
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev = 0;  // Variable to store the maximum sum excluding the current element
    int prev2 = 0; // Variable to store the maximum sum excluding the previous element

    prev = nums[0]; // Initialize 'prev' with the value of the first element in the vector

    // Loop through the array to calculate the maximum sum for each index
    for (int i = 1; i < n; i++)
    {
        int take = nums[i]; // Consider the current element

        // If the current index is greater than 1, add the maximum sum from two indices ago
        if (i > 1)
        {
            take += prev2;
        }

        int nottake = prev; // Skip the current element

        // Choose the maximum between taking and not taking the current element
        int curr = max(take, nottake);

        // Update 'prev2' and 'prev' for the next iteration
        prev2 = prev;
        prev = curr;
    }

    // The final result is stored in 'prev', which represents the maximum sum of non-adjacent elements
    return prev;
}

int main()
{
    return 0;
}