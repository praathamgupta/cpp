#include <bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    int result=0;
    for (int i = 0; i < (m + 1); i++)
    {
        for (int j = 0; j < (n + 1); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1]+1;
                result= max(result,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return result;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();
    cout << lcs(s1, s2, m, n) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}