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
    int solve(int start, int end, vector<int> &cuts)
    {
        if (start > end)
        {
            return 0;
        }
        int minn = 1e9;
        for (int k = start; k <= end; k++)
        {
            int cost = cuts[end + 1] - cuts[start - 1] + solve(start, k - 1, cuts) + solve(k + 1, end, cuts);
            minn = min(minn, cost);
        }
        return minn;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return solve(1, m, cuts);
    }
};
int main()
{
    return 0;
}