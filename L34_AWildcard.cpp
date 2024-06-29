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
    bool solve(int i, int j, string &s, string &t)
    {
        // Base cases
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i < 0 && j >= 0)
        {
            return false;
        }
        if (j < 0 && i >= 0)
        {
            for (int k = 0; k <= i; k++)
            {
                if (s[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if ((s[i] == t[j]) || (s[i] == '?'))
        {
            return solve(i - 1, j - 1, s, t);
        }
        if (s[i] == '*')
        {
            return solve(i - 1, j, s, t) || solve(i, j - 1, s, t);
        }
        return false;
    }

public:
    bool isMatch(string t, string s)
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