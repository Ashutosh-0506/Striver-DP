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
    int solve(int index, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if ((index >= n) || (cap == 0))
        {
            return 0;
        }
        if (dp[index][buy][cap] != -1)
        {
            return dp[index][buy][cap];
        }
        int profit = 0;
        if (buy == 1)
        {
            profit = max(profit, max(-prices[index] + solve(index + 1, 0, cap, n, prices, dp), 0 + solve(index + 1, 1, cap, n, prices, dp)));
        }
        else
        {
            profit = max(profit, max(prices[index] + solve(index + 1, 1, cap - 1, n, prices, dp), 0 + solve(index + 1, 0, cap, n, prices, dp)));
        }
        return dp[index][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int index = 0;
        int cap = 2;
        int buy = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
        return solve(index, buy, cap, n, prices, dp);
    }
};
int main()
{
    return 0;
}