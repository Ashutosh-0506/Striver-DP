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
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int ans = 0;

        int lastindex = 0;
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    hash[i] = prev;
                    dp[i] = 1 + dp[prev];
                }
            }
            if (ans < dp[i])
            {
                lastindex = i;
                ans = dp[i];
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(), temp.end());
        for (auto it : temp)
        {
            cout << it << " ";
        }
        cout << endl;

        return ans;
    }
};
int main()
{
    return 0;
}