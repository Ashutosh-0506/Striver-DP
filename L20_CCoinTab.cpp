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
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int pick = 1e9;
                int notpick = notpick = dp[index - 1][target];

                if (target >= coins[index])
                {
                    pick = 1 + dp[index][target - coins[index]];
                }
                dp[index][target] = min(pick, notpick);
            }
        }
        int ans = dp[n - 1][amount];
        return ans == 1e9 ? -1 : ans;
    }
};
int main()
{
    return 0;
}