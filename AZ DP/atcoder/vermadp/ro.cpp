#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m, int (&dp)[1001][1001])
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, dp);
    }
    else if (s1[n - 1] != s2[m - 1])
    {
        return dp[n][m] = max(lcs(s1, s2, n - 1, m, dp), lcs(s1, s2, n, m - 1, dp));
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        cout << lcs(s1, s2, n, m, dp) << "\n";
    }
    return 0;
}
