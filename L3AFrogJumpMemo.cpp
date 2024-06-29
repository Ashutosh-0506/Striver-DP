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
int solve(int n, int index, vector<int> &heights, vector<int> &dp)
{
    if (index >= n - 1)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    } 
    int path1 = INT_MAX;
    int path2 = INT_MAX;
    if (index + 1 < n)
    {
        path1 = abs(heights[index] - heights[index + 1]) + solve(n, index + 1, heights, dp);
    }
    if (index + 2 < n)
    {
        path2 = abs(heights[index] - heights[index + 2]) + solve(n, index + 2, heights, dp);
    }
    return dp[index] = min(path1, path2);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return solve(n, 0, heights, dp);
}
int main()
{
    return 0;
}