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
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 1; buy >= 0; buy--)
            {
                for (int cap = k; cap > 0; cap--)
                {
                    int profit = 0;
                    if (buy == 1)
                    {
                        profit = max(profit, max(-prices[index] + prev[0][cap], 0 + prev[1][cap]));
                    }
                    else
                    {
                        profit = max(profit, max(prices[index] + prev[1][cap - 1], 0 + prev[0][cap]));
                    }
                    curr[buy][cap] = profit;
                }
                prev = curr;
            }
        }
        return prev[1][k];
    }
};
int main()
{
    return 0;
}