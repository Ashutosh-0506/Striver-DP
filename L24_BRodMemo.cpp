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
int solve(int index, int length, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return length * price[0];
    }
    if (dp[index][length] != -1)
    {
        return dp[index][length];
    }
    int pick = 0;
    int cutlength = index + 1;
    int notpick = solve(index - 1, length, price, dp);
    if (length >= cutlength)
    {
        pick = price[index] + solve(index, length - cutlength, price, dp);
    }
    return dp[index][length] = max(pick, notpick);
}
int cutRod(vector<int> &price, int n)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(index, n, price, dp);
}

int main()
{
    return 0;
}