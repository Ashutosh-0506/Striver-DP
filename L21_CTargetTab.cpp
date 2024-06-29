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
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        int total = 0;
        for (auto &it : nums)
        {
            total += it;
        }
        if ((total - target < 0) || (total - target) & 1)
        {
            return 0;
        }
        int index = n - 1;
        int val = (total - target) / 2;
        vector<vector<int>> dp(n, vector<int>(val + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;
        if (nums[0] != 0 && nums[0] <= val)
            dp[0][nums[0]] = 1;

        for (int index = 1; index < n; index++)
        {
            for (int tar = 0; tar <= val; tar++)
            {
                int pick = 0;
                int notpick = dp[index - 1][tar];
                if (tar - nums[index] >= 0)
                {
                    pick = dp[index - 1][tar - nums[index]];
                }
                dp[index][tar] = pick + notpick;
            }
        }
        return dp[n - 1][val];
    }
};
int main()
{
    return 0;
}