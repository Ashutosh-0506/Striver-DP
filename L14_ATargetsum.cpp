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
#include <bits/stdc++.h>
bool solve(int index, int target, vector<int> &arr)
{
    if (target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    if (index == 0)
    {
        return target == arr[0];
    }
    bool pick = solve(index - 1, target - arr[index], arr);
    bool notpick = solve(index - 1, target, arr);
    return pick || notpick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solve(n - 1, k, arr);
}
int main()
{
    return 0;
}