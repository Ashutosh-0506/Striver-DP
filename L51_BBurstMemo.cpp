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
    int solve(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (start > end)
        {
            return 0;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int maxx = 0;

        for (int k = start; k <= end; k++)
        {
            int cost = nums[start - 1] * nums[end + 1] * nums[k] + solve(start, k - 1, nums, dp) + solve(k + 1, end, nums, dp);
            maxx = max(maxx, cost);
        }
        return dp[start][end] = maxx;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int start = 1;
        int end = n;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(start, end, nums, dp);
    }
};
int main()
{
    return 0;
}