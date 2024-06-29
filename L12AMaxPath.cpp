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
    int solve(int row,int col,int n,vector<vector<int>>&matrix)
    {
        if(row>=n || col>=n || col<0)
        {
            return INT_MAX;
        }
        if(row==n-1)
        {
            return matrix[row][col];
        }
        int prev=solve(row+1,col-1,n,matrix);
        int same=solve(row+1,col,n,matrix);
        int next=solve(row+1,col+1,n,matrix);
        return min(prev,min(same,next))+matrix[row][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int minn=INT_MAX;
        for(int i=0;i<n;i++)
        {
           minn=min(minn,solve(0,i,n,matrix));
        }
        return minn;
    }
};
int main()
{
return 0;
}