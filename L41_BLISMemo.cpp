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
    int solve(int index, int prev, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index >= n)
        {
            return 0;
        }
        if (dp[index][prev + 1] != -1)
        {
            return dp[index][prev + 1];
        }
        int pick = 0;
        int notpick = 0 + solve(index + 1, prev, n, nums, dp);
        if (prev == -1 || nums[prev] < nums[index])
        {
            pick = 1 + solve(index + 1, index, n, nums, dp);
        }
        return dp[index][prev + 1] = max(pick, notpick);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int index = 0;
        int prev = -1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(index, prev, n, nums, dp);
    }
};
int main()
{
    return 0;
}