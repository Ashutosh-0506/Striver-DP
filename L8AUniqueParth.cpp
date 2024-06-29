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
class Solution
{
private:
    int solve(int row, int col)
    {
        if (row == 0 && col == 0)
        {
            return 1;
        }
        if (row < 0 || col < 0)
        {
            return 0;
        }
        int up = solve(row - 1, col);
        int right = solve(row, col - 1);
        return up + right;
    }

public:
    int uniquePaths(int m, int n)
    {
        return solve(m - 1, n - 1);
    }
};
int main()
{
    return 0;
}