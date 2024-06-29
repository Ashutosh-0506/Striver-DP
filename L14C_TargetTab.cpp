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
 #include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;

    for(int index=1;index<n;index++)
    {
        for(int target=1;target<=k;target++)
        {
            bool pick=false;
            if(target>=arr[index])
            {
                pick=dp[index-1][target-arr[index]];
            }
            bool notpick=dp[index-1][target];
            dp[index][target]= pick || notpick;
        }
    }
    return dp[n-1][k];
}
int main()
{
return 0;
}