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
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int start = n; start >= 1; start--)
        {
            for (int end = start; end <= n; end++)
            {
                int maxx = 0;
                for (int k = start; k <= end; k++)
                {
                    int cost = nums[start - 1] * nums[end + 1] * nums[k] + dp[start][k - 1] + dp[k + 1][end];
                    maxx = max(maxx, cost);
                }
                dp[start][end] = maxx;
            }
        }
        return dp[1][n];
    }
};
int main()
{
    return 0;
}