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
 

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=accumulate(arr.begin(),arr.end(),0);
	vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
	for(int i=0;i<n;i++)
	{
		dp[i][0]=true;
	}
	if(arr[0]<=sum)
	{
		dp[0][arr[0]]=true;
	}
	for(int index=1;index<n;index++)
	{
		for(int target=1;target<=sum;target++)
		{
			bool pick=false;
			if(target>=arr[index])
			{
				pick=dp[index-1][target-arr[index]];
			}
			bool notpick=dp[index-1][target];
			dp[index][target]=pick || notpick;
		}
	}
	       


	int minn=INT_MAX;
	for(int i=0;i<=sum;i++)
	{
		int s1=i;
		int s2=sum-i;
		if(dp[n-1][i]==true)
		{
			minn=min(minn,abs(s1-s2));
		}
	}
	return minn;
}

int main()
{
return 0;
}