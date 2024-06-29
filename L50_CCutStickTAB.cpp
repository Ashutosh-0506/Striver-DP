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
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for (int start = c; start >= 1; start--)
        {
            for (int end = start; end <= c; end++)
            {
                int minn = 1e9;
                for (int k = start; k <= end; k++)
                {
                    int cost = cuts[end + 1] - cuts[start - 1] + dp[start][k - 1] + dp[k + 1][end];
                    minn = min(minn, cost);
                }
                dp[start][end] = minn;
            }
        }
        return dp[1][c];
    }
};
int main()
{
    return 0;
}