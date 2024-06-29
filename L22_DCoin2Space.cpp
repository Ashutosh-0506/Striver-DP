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
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
            {
                prev[target] = 1;
            }
        }

        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int pick = 0;
                int notpick = prev[target];
                if (target >= coins[index])
                {
                    pick = curr[target - coins[index]];
                }
                curr[target] = pick + notpick;
            }
            prev = curr;
        }
        return prev[amount];
    }
};
int main()
{
    return 0;
}