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
#include<bits/stdc++.h>
using namespace ::std;
 class Solution {
    int solve(int index,int target,vector<int>&nums)
    {
        if (index == 0)
        {
            if (target == 0 && nums[0] == 0)
            {
                return 2;
            }
            if ((target == 0 ) || (target == nums[0]))
            {
                return 1;
            }
            return 0;
        }

        int pick=0;
        int notpick=solve(index-1,target,nums);
        if(target-nums[index]>=0)
        {
            pick=solve(index-1,target-nums[index],nums);
        }
        return pick+notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        int total=0;
        for(auto &it:nums)
        {
            total+=it;
        }
        if((total-target<0)||(total-target)&1)
        {
            return 0;
        }
        int index=n-1;
        return solve(index,(total-target)/2,nums);
    }
};
int main()
{
return 0;
}