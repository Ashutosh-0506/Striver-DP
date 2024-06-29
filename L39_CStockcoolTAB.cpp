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
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int index = 0;
        int buy = 1;
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                int profit = 0;
                if (buy == 1)
                {
                    profit = max(profit, max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]));
                }
                else
                {
                    profit = max(profit, max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]));
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
int main()
{
    return 0;
}