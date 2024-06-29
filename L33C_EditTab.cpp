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
public:
    int minDistance(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int ins = 1e9;
                    int del = 1e9;
                    int rep = 1e9;
                    ins = dp[i][j - 1] + 1;
                    del = dp[i - 1][j] + 1;
                    rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(ins, min(del, rep));
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{
    return 0;
}