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
bool solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (index == 0)
    {
        return arr[0] == target;
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    bool pick = false;
    if (target >= arr[index])
    {
        pick = solve(index - 1, target - arr[index], arr, dp);
    }
    bool notpick = solve(index - 1, target, arr, dp);
    return dp[index][target] = pick || notpick;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    for (int i = 0; i <= sum; ++i)
    {
        solve(n - 1, i, arr, dp);
    }

    int minn = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
        int s1 = i;
        int s2 = sum - i;
        if (dp[n - 1][i] == true)
        {
            minn = min(minn, abs(s1 - s2));
        }
    }
    return minn;
}

int main()
{
    return 0;
}