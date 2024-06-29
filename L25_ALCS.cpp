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
    int solve(int index1, int index2, string &text1, string &text2)
    {
        if (index1 < 0 || index2 < 0)
        {
            return 0;
        }
        if (text1[index1] == text2[index2])
        {
            return 1 + solve(index1 - 1, index2 - 1, text1, text2);
        }
        return max(solve(index1, index2 - 1, text1, text2), solve(index1 - 1, index2, text1, text2));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        return solve(n - 1, m - 1, text1, text2);
    }
};
int main()
{
    return 0;
}