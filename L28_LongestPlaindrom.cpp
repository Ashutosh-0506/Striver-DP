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
    int solve(string &s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        for (int index1 = 1; index1 <= n; index1++)
        {
            for (int index2 = 1; index2 <= m; index2++)
            {
                if (s[index1 - 1] == t[index2 - 1])
                {
                    curr[index2] = 1 + prev[index2 - 1];
                }
                else
                {
                    curr[index2] = max(curr[index2 - 1], prev[index2]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        return solve(s);
    }
};
int main()
{
    return 0;
}