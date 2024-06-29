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
    int solve(int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (start > end)
        {
            return 0;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int minn = 1e9;
        for (int k = start; k <= end; k++)
        {
            int cost = cuts[end + 1] - cuts[start - 1] + solve(start, k - 1, cuts, dp) + solve(k + 1, end, cuts, dp);
            minn = min(minn, cost);
        }
        return dp[start][end] = minn;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(1, c, cuts, dp);
    }
};
int main()
{
    return 0;
}