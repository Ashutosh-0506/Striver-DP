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
    int solve(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (text1[index1] == text2[index2])
        {
            int match = 1;
            if (index1 > 0 && index2 > 0)
            {
                match += solve(index1 - 1, index2 - 1, text1, text2, dp);
            }
            return dp[index1][index2] = match;
        }
        int notmatch1 = 0;
        int notmatch2 = 0;
        if (index2 > 0)
        {
            notmatch1 += solve(index1, index2 - 1, text1, text2, dp);
        }
        if (index1 > 0)
        {
            notmatch2 += solve(index1 - 1, index2, text1, text2, dp);
        }
        return dp[index1][index2] = max(notmatch1, notmatch2);
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, text1, text2, dp);
    }
};
int main()
{
    return 0;
}