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
#include <bits/stdc++.h>

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int index1 = 0; index1 <= n; index1++)
    {
        dp[index1][0] = 0;
    }
    for (int index2 = 0; index2 <= m; index2++)
    {
        dp[0][index2] = 0;
    }
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (s[index1 - 1] == t[index2 - 1])
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
    // Printing
    string st = "";
    for (int i = 0; i < dp[n][m]; i++)
    {
        st += ' ';
    }
    int i = n;
    int j = m;

    int stindex = dp[n][m] - 1;
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            st[stindex] = s[i - 1];
            stindex--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << st << endl;

    return dp[n][m];
}

int main()
{
    cout<<lcs("abc","bcd")<<endl;
    return 0;
}