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

        vector<int> temp;
        temp.push_back(nums[0]);
        int ans = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                ans++;
                temp.push_back(nums[i]);
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}