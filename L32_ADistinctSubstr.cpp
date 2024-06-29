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
    int solve(int i, int j, string &s, string &t)
    {
        if (j < 0)
        {
            return 1;
        }
        if (i < 0)
        {
            return 0;
        }

        if (s[i] == t[j])
        {
            return (solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t));
        }
        return solve(i - 1, j, s, t);
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        return solve(n - 1, m - 1, s, t);
    }
};
int main()
{
    return 0;
}