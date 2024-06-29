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
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{

    vector<int> prev(w + 1, 0);

    for (int maxx = 0; maxx <= w; maxx++)
    {

        prev[maxx] = (maxx / weight[0]) * profit[0];
    }

    for (int index = 1; index < n; index++)
    {
        for (int maxx = 0; maxx <= w; maxx++)
        {
            int pick = 0;
            int notpick = prev[maxx];
            if (maxx >= weight[index])
            {
                pick = profit[index] + prev[maxx - weight[index]];
            }
            prev[maxx] = max(pick, notpick);
        }
    }
    return prev[w];
}
int main()
{
    return 0;
}