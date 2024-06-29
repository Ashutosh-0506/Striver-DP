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
    bool isMatch(string t, string s)
    {
        int n = s.size();
        int m = t.size();

        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);

        prev[0] = true;
        for (int j = 1; j <= m; j++)
        {
            prev[j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            bool flag = true;
            for (int k = 1; k <= i; k++)
            {
                if (s[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {
                if ((s[i - 1] == t[j - 1]) || (s[i - 1] == '?'))
                {
                    curr[j] = prev[j - 1];
                }
                else if (s[i - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
int main()
{
    return 0;
}