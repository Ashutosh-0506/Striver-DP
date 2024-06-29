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

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (k == 0 && arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }
    if (arr[0] != 0 && arr[0] <= k)
    {
        dp[0][arr[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int MOD = 1e9 + 7;
            int pick = 0;
            if (target - arr[index] >= 0)
            {
                pick = dp[index - 1][target - arr[index]] % MOD;
            }
            int notpick = notpick = dp[index - 1][target] % MOD;

            dp[index][target] = (pick + notpick) % MOD;
        }
    }
    return dp[n - 1][k];
}

int main()
{
    return 0;
}