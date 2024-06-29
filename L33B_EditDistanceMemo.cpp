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
class Solution
{
private:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
            return j + 1;
        }
        if (j < 0)
        {
            return i + 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j])
        {
            return 0 + solve(i - 1, j - 1, s, t, dp);
        }
        int ins = 1e9;
        int del = 1e9;
        int rep = 1e9;
        ins = solve(i, j - 1, s, t, dp) + 1;
        del = solve(i - 1, j, s, t, dp) + 1;
        rep = solve(i - 1, j - 1, s, t, dp) + 1;
        return dp[i][j] = min(ins, min(del, rep));
    }

public:
    int minDistance(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};
int main()
{
    return 0;
}