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

int cutRod(vector<int> &price, int n)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int length = 0; length <= n; length++)
    {
        dp[0][length] = length * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int length = 0; length <= n; length++)
        {
            int pick = 0;
            int cutlength = index + 1;
            int notpick = dp[index - 1][length];
            if (length >= cutlength)
            {
                pick = price[index] + dp[index][length - cutlength];
            }
            dp[index][length] = max(pick, notpick);
        }
    }
    return dp[n - 1][n];
}

int main()
{
    return 0;
}