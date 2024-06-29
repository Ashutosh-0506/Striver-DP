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


int solve(int index, int prev, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[index][prev] != -1)
    {
        return dp[index][prev];
    }
    int maxx = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        if (i != prev)
        {
            temp = points[index][i] + solve(index - 1, i, n, points, dp);
        }
        maxx = max(maxx, temp);
    }
    return dp[index][prev] = maxx;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, n, points, dp);
}
int main()
{
    return 0;
}