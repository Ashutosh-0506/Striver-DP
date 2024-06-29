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
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int minn=INT_MAX;
        vector<int>prevv(n,0);
        for(int i=0;i<n;i++)
        {
           prevv[i]=matrix[n-1][i];
        }
        for(int row=n-2;row>=0;row--)
        {
            vector<int>curr(n,0);
            for(int col=n-1;col>=0;col--)
            {
                int prev=INT_MAX;
                int same=INT_MAX;
                int next=INT_MAX;
                if(col-1>=0)
                {
                    prev=prevv[col-1];
                }
                same=prevv[col];
                if(col+1<n)
                {
                    next=prevv[col+1];
                }
                curr[col]=min(same,min(prev,next))+matrix[row][col];
            }
            prevv=curr;
        }
        for(int i=0;i<n;i++)
        {
            minn=min(minn,prevv[i]);
        }
        return minn;
    }
};
int main()
{
return 0;
}