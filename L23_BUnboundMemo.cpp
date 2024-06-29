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
int solve(int index, int maxx, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (index == 0)
    {

        return (maxx / weight[0]) * profit[0];
    }
    if (dp[index][maxx] != -1)
    {
        return dp[index][maxx];
    }
    int pick = 0;
    int notpick = solve(index - 1, maxx, profit, weight, dp);
    if (maxx >= weight[index])
    {
        pick = profit[index] + solve(index, maxx - weight[index], profit, weight, dp);
    }
    return dp[index][maxx] = max(pick, notpick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return solve(index, w, profit, weight, dp);
}
int main()
{
    return 0;
}