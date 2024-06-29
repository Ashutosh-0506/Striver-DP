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
        int minn = prices[0];
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            minn = min(minn, prices[i]);
            profit = max(profit, (prices[i] - minn));
        }
        return profit;
    }
};
int main()
{
    return 0;
}