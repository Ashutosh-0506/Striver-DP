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
int evaluateExp(string &exp)
{
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = 0; end < n; end++)
        {
            for (int isTrue = 1; isTrue >= 0; isTrue--)
            {
                if (start > end)
                {
                    continue;
                }
                if (start == end)
                {
                    if (isTrue == 1)
                    {
                        dp[start][end][isTrue] = exp[start] == 'T';
                    }
                    else
                    {
                        dp[start][end][isTrue] = exp[start] == 'F';
                    }
                }
                else
                {
                    int MOD = 1e9 + 7;
                    long long ways = 0;

                    for (int k = start + 1; k <= end - 1; k = k + 2)
                    {
                        long long LT = dp[start][k - 1][1] % MOD;
                        long long LF = dp[start][k - 1][0] % MOD;
                        long long RT = dp[k + 1][end][1] % MOD;
                        long long RF = dp[k + 1][end][0] % MOD;

                        long long count = 0;
                        if (exp[k] == '&')
                        {
                            if (isTrue == 1)
                            {
                                count = (count + (LT * RT) % MOD) % MOD;
                            }
                            else
                            {
                                count = (count + (LF * RF) % MOD + (LF * RT) % MOD + (LT * RF) % MOD) % MOD;
                            }
                        }
                        else if (exp[k] == '|')
                        {
                            if (isTrue == 1)
                            {
                                count = (count + (LT * RT) % MOD + (LF * RT) % MOD + (LT * RF) % MOD) % MOD;
                            }
                            else
                            {
                                count = (count + (LF * RF) % MOD) % MOD;
                            }
                        }
                        else
                        {
                            if (isTrue == 1)
                            {
                                count = (count + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
                            }
                            else
                            {
                                count = (count + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
                            }
                        }
                        ways = (ways + count) % MOD;
                    }
                    dp[start][end][isTrue] = ways;
                }
            }
        }
    }
    return dp[0][n - 1][1];
}
int main()
{
    return 0;
}