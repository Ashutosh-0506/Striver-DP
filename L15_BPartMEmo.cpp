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
    bool solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (index == 0)
        {
            return target == nums[0];
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        bool pick = false;
        if (target >= nums[index])
        {
            pick = solve(index - 1, target - nums[index], nums, dp);
        }
        bool notpick = solve(index - 1, target, nums, dp);
        return dp[index][target] = pick || notpick;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
        {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));
        return solve(n - 1, sum / 2, nums, dp);
    }
};
int main()
{
    return 0;
}