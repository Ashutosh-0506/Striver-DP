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
    int solve(int index, int buy, int cap, int n, vector<int> &prices)
    {
        if ((index >= n) || (cap == 0))
        {
            return 0;
        }
        int profit = 0;
        if (buy == 1)
        {
            profit = max(profit, max(-prices[index] + solve(index + 1, 0, cap, n, prices), 0 + solve(index + 1, 1, cap, n, prices)));
        }
        else
        {
            profit = max(profit, max(prices[index] + solve(index + 1, 1, cap - 1, n, prices), 0 + solve(index + 1, 0, cap, n, prices)));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int index = 0;
        int cap = 2;
        int buy = 1;
        return solve(index, buy, cap, n, prices);
    }
};
int main()
{
    return 0;
}