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

// TLE by Recursion

// 1>
// void solve(int n, int index, vector<pair<int, int>> &temp, vector<vector<pair<int, int>>> &ans, vector<int> &nums)
// {
//     if (index == n)
//     {
//         if (temp.size() != 0)
//         {
//             for (int i = 0; i < temp.size() - 1; i++)
//             {
//                 if ((temp[i].second == temp[i + 1].second + 1) || (temp[i].second == temp[i + 1].second - 1))
//                 {
//                     return;
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return;
//     }
//     temp.push_back({nums[index],index});
//     solve(n,index+1,temp,ans,nums);
//     temp.pop_back();
//     solve(n,index+1,temp,ans,nums);
// }
// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int n = nums.size();
//     int index = 0;
//     vector<pair<int, int>> temp;
//     vector<vector<pair<int, int>>> ans;
//     solve(n, index, temp, ans, nums);
//     int sum=INT_MIN;
//     for(auto it:ans)
//     {
//         int val=0;
//         for(auto tt:it)
//         {
//             val+=tt.first;
//         }
//         sum=max(sum,val);
//     }
//     return sum;
// }

// 2>
void solve(int n, int index, vector<int> &temp, vector<vector<int>> &ans, vector<int> &nums)
{
    if (index >= n)
    {
        if (temp.size() != 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    temp.push_back(nums[index]);
    solve(n, index + 2, temp, ans, nums);
    temp.pop_back();
    solve(n, index + 1, temp, ans, nums);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int index = 0;
    vector<int> temp;
    vector<vector<int>> ans;
    solve(n, index, temp, ans, nums);
    int sum = INT_MIN;
    for (auto it : ans)
    {
        int val = 0;
        for (auto tt : it)
        {
            val += tt;
        }
        sum = max(sum, val);
    }
    return sum;
}

int main()
{
    return 0;
}