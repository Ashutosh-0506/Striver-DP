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
    bool isMatch(string t, string s)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (s[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if ((s[i - 1] == t[j - 1]) || (s[i - 1] == '?'))
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (s[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = false;
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