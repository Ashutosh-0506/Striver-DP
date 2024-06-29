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
    int solve(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        int pick = 0;
        int notpick = solve(index - 1, target, coins, dp);
        if (target >= coins[index])
        {
            pick = solve(index, target - coins[index], coins, dp);
        }
        return dp[index][target] = pick + notpick;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(index, amount, coins, dp);
    }
};
int main()
{
    return 0;
}