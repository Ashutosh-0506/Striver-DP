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
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int start = N - 1; start >= 1; start--)
    {
        for (int end = start + 1; end < N; end++)
        {
            int minn = 1e9;
            for (int k = start; k < end; k++)
            {
                int steps = arr[start - 1] * arr[k] * arr[end] + dp[start][k] + dp[k + 1][end];
                minn = min(minn, steps);
            }
            dp[start][end] = minn;
        }
    }
    return dp[1][N - 1];
}
int main()
{
    return 0;
}