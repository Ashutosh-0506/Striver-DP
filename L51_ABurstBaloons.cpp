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
    int solve(int start, int end, vector<int> &nums)
    {
        if (start > end)
        {
            return 0;
        }

        int maxx = 0;

        for (int k = start; k <= end; k++)
        {
            int cost = nums[start - 1] * nums[end + 1] * nums[k] + solve(start, k - 1, nums) + solve(k + 1, end, nums);
            maxx = max(maxx, cost);
        }
        return maxx;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int start = 1;
        int end = n;
        return solve(start, end, nums);
    }
};
int main()
{
    return 0;
}