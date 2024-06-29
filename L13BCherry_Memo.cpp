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
    private:
    int solve(int row,int col1,int col2,int n,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        if(row>=n || col1>=m || col2>=m || col1<0 || col2<0)
        {
            return -1e8;
        }
        if(row==n-1)
        {
            if(col1==col2)
            {
                return grid[row][col1];
            }
            return grid[row][col1]+grid[row][col2];
        }
        if(dp[row][col1][col2]!=-1)
        {
            return dp[row][col1][col2];
        }
        int val=col1==col2?(grid[row][col1]):(grid[row][col1]+grid[row][col2]);

        int maxx=0;
        for(int ncol1=-1;ncol1<=1;ncol1++)
        {
            for(int ncol2=-1;ncol2<=1;ncol2++)
            {
                maxx=max(maxx,solve(row+1,col1+ncol1,col2+ncol2,n,m,grid,dp));
            }
        }
        return dp[row][col1][col2]= val+maxx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,grid,dp);
    }
};
int main()
{
return 0;
}