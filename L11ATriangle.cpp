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
    int solve(int step, int index, int n, vector<vector<int>> &triangle)
    {
        if (step == n - 1)
        {
            return triangle[step][index];
        }
        int down = solve(step + 1, index, n, triangle) + triangle[step][index];
        int diagonal = solve(step + 1, index + 1, n, triangle) + triangle[step][index];
        return min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        return solve(0, 0, n, triangle);
    }
};
int main()
{
    return 0;
}