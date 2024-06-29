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
private:
    // Function to calculate the length of the longest bitonic subsequence
    int bitonic(vector<int> &nums, int n)
    {
        // Calculating Longest Increasing Subsequence (LIS)
        vector<int> LIS(n, 1); // Initialize LIS array with 1, as the minimum length is 1

        // Compute LIS values for all elements
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && LIS[i] < LIS[j] + 1)
                {
                    LIS[i] = LIS[j] + 1; // Update LIS[i] if a longer subsequence ending at i is found
                }
            }
        }

        // Calculating Longest Decreasing Subsequence (LDS)
        vector<int> LDS(n, 1); // Initialize LDS array with 1, as the minimum length is 1
        int maxx = 0;               // Variable to store the maximum length of bitonic subsequence

        // Compute LDS values for all elements from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (nums[i] > nums[j] && LDS[i] < LDS[j] + 1)
                {
                    LDS[i] = LDS[j] + 1; // Update LDS[i] if a longer subsequence starting at i is found
                }
            }
            // Ensure it's a valid bitonic subsequence (LIS and LDS lengths should be > 1)
            if (LIS[i] > 1 && LDS[i] > 1)
            {
                maxx = max(maxx, LIS[i] + LDS[i] - 1); // Calculate and update the maximum bitonic subsequence length
            }
        }
        return maxx; // Return the length of the longest bitonic subsequence
    }

public:
    // Function to calculate the minimum number of removals to make the array a mountain array
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        return n - bitonic(nums, n); // Total elements minus the longest bitonic subsequence gives the minimum removals
    }
};

int main()
{
    return 0;
}