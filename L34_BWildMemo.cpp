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
    bool solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        // Base cases
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if ((s[i] == t[j]) || (s[i] == '?'))
        {
            return dp[i][j] = solve(i - 1, j - 1, s, t, dp);
        }
        if (s[i] == '*')
        {
            return dp[i][j] = solve(i - 1, j, s, t, dp) || solve(i, j - 1, s, t, dp);
        }
        return dp[i][j] = false;
    }

public:
    bool isMatch(string t, string s)
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