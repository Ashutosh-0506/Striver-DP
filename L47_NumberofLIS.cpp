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
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] represents the length of the longest increasing subsequence ending at index i
        vector<int> dp(n, 1);
        // count[i] represents the number of longest increasing subsequences ending at index i
        vector<int> count(n, 1);
        int maxx = 0; // Variable to keep track of the maximum length of LIS

        // Iterate through each element
        for (int i = 0; i < n; i++)
        {
            // For each element, check all previous elements
            for (int j = 0; j < i; j++)
            {
                // If nums[i] can extend the increasing subsequence ending at nums[j]
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;   // Update the length of LIS ending at i
                    count[i] = count[j]; // Update the count of LIS ending at i
                }
                // If nums[i] can extend the increasing subsequence ending at nums[j] and lengths are equal
                else if (nums[i] > nums[j] && dp[i] == dp[j] + 1)
                {
                    count[i] += count[j]; // Increment the count of LIS ending at i
                }
            }
            // Update the maximum length of LIS found so far
            if (maxx < dp[i])
            {
                maxx = dp[i];
            }
        }

        int nos = 0; // Variable to count the number of longest increasing subsequences
        // Iterate through each element to count the number of LIS of maximum length
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxx)
            {
                nos += count[i];
            }
        }
        return nos; // Return the number of longest increasing subsequences
    }
};

int main()
{
    return 0;
}