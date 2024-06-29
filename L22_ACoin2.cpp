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
    int solve(int index, int amount, vector<int> &coins)
    {
        if (index == 0)
        {
            if (amount % coins[0] == 0)
            {
                return 1;
            }
            return 0;
        }
        int pick = 0;
        int notpick = solve(index - 1, amount, coins);
        if (amount >= coins[index])
        {
            pick = solve(index, amount - coins[index], coins);
        }
        return pick + notpick;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int index = n - 1;
        return solve(index, amount, coins);
    }
};
int main()
{
    return 0;
}