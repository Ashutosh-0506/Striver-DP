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

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int k = sum / 2 + 1;
    vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);

    prev[0] = true;
    curr[0] = true;
    if (arr[0] <= sum)
    {
        prev[arr[0]] = true;
    }
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool pick = false;
            if (target >= arr[index])
            {
                pick = prev[target - arr[index]];
            }
            bool notpick = prev[target];
            curr[target] = pick || notpick;
        }
        prev = curr;
    }

    int minn = INT_MAX;
    for (int i = 0; i <= k; i++)
    {
        int s1 = i;
        int s2 = sum - i;
        if (prev[i] == true)
        {
            minn = min(minn, abs(s1 - s2));
        }
    }
    return minn;
}

int main()
{
    return 0;
}