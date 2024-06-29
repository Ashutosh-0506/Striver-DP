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
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        prev[0] = 1;
        curr[0] = 1;

        int MOD = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = ((prev[j - 1]) % MOD + (prev[j]) % MOD) % MOD;
                }
                else
                {
                    curr[j] = (prev[j]) % MOD;
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