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
int solve(int index, int prev, int n, vector<vector<int>> &points)
{
    if (index >= n)
    {
        return 0;
    }
    int maxx = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        if (i != prev)
        {
            temp = points[index][i] + solve(index + 1, i, n, points);
        }
        maxx = max(maxx, temp);
    }
    return maxx;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int n = points.size();
    int index = 0;
    return solve(0, -1, n, points);
}
int main()
{
    return 0;
}