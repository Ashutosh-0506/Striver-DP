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
        vector<int> prevv(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = n - 1; prev >= -1; prev--)
            {
                int pick = 0;
                int notpick = 0 + prevv[prev + 1];
                if (prev == -1 || nums[prev] < nums[index])
                {
                    pick = 1 + prevv[index + 1];
                }
                curr[prev + 1] = max(pick, notpick);
            }
            prevv = curr;
        }
        return prevv[0];
    }
};
int main()
{
    return 0;
}