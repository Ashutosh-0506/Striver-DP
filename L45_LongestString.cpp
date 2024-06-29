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
    static bool cmp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    bool compare(string &s, string &t)
    {
        int n = s.size();
        int m = t.size();
        if (n != m + 1)
        {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < n)
        {
            if (j < m && s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return (i == n && j == m);
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);

        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (ans < dp[i])
            {
                ans = dp[i];
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}