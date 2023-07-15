// it is just like lcs
//  here the second string is reverse of first string
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int lcs(string s1, string s2, int n, int m)
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
        return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    }
    else if (s1[n - 1] != s2[m - 1])
    {
        return dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
}
void solve()
{
    string s1;
    cin >> s1;
    int n = s1.size();
    string s2 = s1;
    int m = s2.size();
    reverse(s2.begin(), s2.end());
    memset(dp, -1, sizeof(dp));
     cout << lcs(s1, s2, n, m);
}
int main()
{
    solve();
}