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
#include <bits/stdc++.h>

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int maxx = 0; maxx <= maxWeight; maxx++)
    {
        if (weight[0] <= maxx)
        {
            dp[0][maxx] = value[0];
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int maxx = 0; maxx <= maxWeight; maxx++)
        {
            int pick = INT_MIN;
            int notpick = dp[index - 1][maxx];

            if (maxx >= weight[index])
            {
                pick = value[index] + dp[index - 1][maxx - weight[index]];
            }
            dp[index][maxx] = max(pick, notpick);
        }
    }
    return dp[n - 1][maxWeight];
}
int main()
{
    return 0;
}