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

int solve(int start, int end, vector<int> &arr)
{
    if (start == end)
    {
        return 0;
    }
    int minn = 1e9;
    for (int k = start; k < end; k++)
    {
        int steps = arr[start - 1] * arr[k] * arr[end] + solve(start, k, arr) + solve(k + 1, end, arr);
        minn = min(minn, steps);
    }
    return minn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    int start = 1;
    int end = N - 1;
    return solve(start, end, arr);
}
int main()
{
    return 0;
}