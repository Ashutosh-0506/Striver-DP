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
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int index1 = 0; index1 < n; index1++)
        {
            for (int index2 = 0; index2 < m; index2++)
            {
                if (text1[index1] == text2[index2])
                {
                    int match = 1;
                    if (index1 > 0 && index2 > 0)
                    {
                        match += dp[index1 - 1][index2 - 1];
                    }
                    dp[index1][index2] = match;
                }
                else
                {
                    int notmatch1 = 0;
                    int notmatch2 = 0;
                    if (index2 > 0)
                    {
                        notmatch1 += dp[index1][index2 - 1];
                    }
                    if (index1 > 0)
                    {
                        notmatch2 += dp[index1 - 1][index2];
                    }
                    dp[index1][index2] = max(notmatch1, notmatch2);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
int main()
{
    return 0;
}