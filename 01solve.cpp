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
 
int solve(int row,int col,int n, int m, vector<vector<int>>&mat,vector<vector<int>>&dp)
{
    if(row>=n || col>=m)
    {
        return 0;
    }

    if(row==n-1 && col==m-1)
    {
        return 1;
    }
    if(mat[row][col]==-1)
    {
        return 0;
    }

    if(dp[row][col]!=-1)
    {
        return dp[row][col];
    }
    int MOD=1e9+7;
    int down=solve(row+1,col,n,m,mat,dp)%MOD;
    int right=solve(row,col+1,n,m,mat,dp)%MOD;
    return dp[row][col]= (right+down)%MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int row=0;
    int col=0;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(row,col,n,m,mat,dp);
}
int main()
{
return 0;
}