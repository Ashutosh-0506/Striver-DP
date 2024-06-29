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
int solve(int index, vector<int> &weight, vector<int> &value, int maxx, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (maxx >= weight[0])
            return value[0];
        return 0;
    }
    if (dp[index][maxx] != -1)
    {
        return dp[index][maxx];
    }
    int pick = INT_MIN;
    int notpick = solve(index - 1, weight, value, maxx, dp);
    if (maxx >= weight[index])
    {
        pick = value[index] + solve(index - 1, weight, value, maxx - weight[index], dp);
    }
    return dp[index][maxx] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(index, weight, value, maxWeight, dp);
}
int main()
{
    return 0;
}