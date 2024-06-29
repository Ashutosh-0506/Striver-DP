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
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Create a 2D DP (Dynamic Programming) table to store the maximum points
    // dp[i][j] represents the maximum points at day i, considering the last activity as j
    vector<int> dp(4, 0);

    // Base case: Initialize the DP table for the first day (day 0)
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);

        for (int last = 0; last < 4; last++)
        {
            int maxx = 0;

            // Iterate through the tasks for the current day
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int val = points[day][task] + dp[task];

                    // Update the maximum points for the current day and last activity
                    maxx = max(maxx, val);
                    temp[last] = maxx;
                }
            }
        }
        dp = temp;
    }

    // The maximum points for the last day with any activity can be found in dp[n-1][3]
    return dp[3];
}

int main()
{
    return 0;
}