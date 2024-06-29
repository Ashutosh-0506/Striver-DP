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
  // Space Optimization Solution
int frogJump(int n, vector<int> &heights)
{
    int next1=0;
    int next2;
    for(int i=n-2;i>=0;i--)
    {
        int path1=INT_MAX;
        int path2=INT_MAX;
        if(i+1<n)
        {
            path1=abs(heights[i]-heights[i+1])+next1;
        }
        if(i+2<n)
        {
            path2=abs(heights[i]-heights[i+2])+next2;
        }
        int curr=min(path1,path2);
        next2=next1;
        next1=curr;
    }
    return next1;
}
int main()
{
return 0;
}