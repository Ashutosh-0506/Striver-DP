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

long long solve(int start, int end, int istrue, string &exp, vector<vector<vector<int>>> &dp)
{
    int MOD = 1e9 + 7;
    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {
        if (istrue == 1)
        {
            return exp[start] == 'T';
        }
        else
        {
            return exp[start] == 'F';
        }
    }
    if (dp[start][end][istrue] != -1)
    {
        return dp[start][end][istrue];
    }
    long long ways = 0;

    for (int k = start + 1; k <= end - 1; k = k + 2)
    {
        long long LT = solve(start, k - 1, 1, exp, dp) % MOD;
        long long LF = solve(start, k - 1, 0, exp, dp) % MOD;
        long long RT = solve(k + 1, end, 1, exp, dp) % MOD;
        long long RF = solve(k + 1, end, 0, exp, dp) % MOD;

        long long count = 0;
        if (exp[k] == '&')
        {
            if (istrue == 1)
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
            if (istrue == 1)
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
            if (istrue == 1)
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
    return dp[start][end][istrue] = ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    int start = 0;
    int end = n - 1;
    int istrue = 1;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(start, end, istrue, exp, dp);
}
#include <bits/stdc++.h>

long long solve(int start,int end,int istrue,string &exp,vector<vector<vector<int>>>&dp)
{
    int MOD = 1e9 + 7;
    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {
        if (istrue == 1)
        {
            return exp[start] == 'T';
        }
        else
        {
            return exp[start] == 'F';
        }
    }
    if (dp[start][end][istrue] != -1)
    {
        return dp[start][end][istrue];
    }
    long long ways = 0;

    for (int k = start + 1; k <= end - 1; k = k + 2)
    {
        long long LT = solve(start, k - 1, 1, exp, dp) % MOD;
        long long LF = solve(start, k - 1, 0, exp, dp) % MOD;
        long long RT = solve(k + 1, end, 1, exp, dp) % MOD;
        long long RF = solve(k + 1, end, 0, exp, dp) % MOD;

        long long count = 0;
        if (exp[k] == '&')
        {
            if (istrue == 1)
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
            if (istrue == 1)
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
            if (istrue == 1)
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
    return dp[start][end][istrue] = ways;
}

int evaluateExp(string &exp)
{
    int n = exp.size();
    int start = 0;
    int end = n - 1;
    int istrue = 1;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(start, end, istrue, exp, dp);
}
int main()
{
    return 0;
}