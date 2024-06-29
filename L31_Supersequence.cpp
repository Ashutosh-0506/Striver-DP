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
    string shortestCommonSupersequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        string ans = "";
        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s[i - 1];
                i--;
            }
            else
            {
                ans += t[j - 1];
                j--;
            }
        }

        while (i > 0)
        {
            ans += s[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += t[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    return 0;
}