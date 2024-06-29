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
int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
        {
            return 2;
        }
        if ((target == 0 && arr[0] != 0) || (target == arr[0]))
        {
            return 1;
        }
        return 0;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    int MOD = 1e9 + 7;
    int pick = 0;
    if (target - arr[index] >= 0)
    {
        pick = solve(index - 1, target - arr[index], arr, dp) % MOD;
    }
    int notpick = solve(index - 1, target, arr, dp) % MOD;
    return dp[index][target] = (pick + notpick) % MOD;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(index, k, arr, dp);
}

int main()
{
    return 0;
}