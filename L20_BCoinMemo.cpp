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
    int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
            {
                return amount / coins[0];
            }
            return 1e9;
        }
        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }
        int pick = 1e9;
        int notpick = solve(index - 1, amount, coins, dp);
        if (amount >= coins[index])
        {
            pick = 1 + solve(index, amount - coins[index], coins, dp);
        }
        return dp[index][amount] = min(pick, notpick);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(index, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
int main()
{
    return 0;
}