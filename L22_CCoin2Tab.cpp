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
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int index = n - 1;
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
            {
                dp[0][target] = 1;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int pick = 0;
                int notpick = dp[index - 1][target];
                if (target >= coins[index])
                {
                    pick = dp[index][target - coins[index]];
                }
                dp[index][target] = pick + notpick;
            }
        }
        return dp[n - 1][amount];
    }
};
int main()
{
    return 0;
}