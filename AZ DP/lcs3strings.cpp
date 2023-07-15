#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;
int n, m, c;
int dp[100][100][100];
int rec(int i, int j, int k)
{
    if (i >= s1.length() || j >= s2.length() || k >= s3.length())
    {
        return 0;
    }
    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
    int ans = 0;
    rec(i + 1, j, k);
    rec(i, j + 1, k);
    rec(i + 1, j, k + 1);
    if (s1[i] == s2[j] && s2[j] == s3[k] && s1[i] == s3[k])
    {
        ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
    }
    return dp[i][j][k] = ans;
}
void solve()
{
    cin >> s1 >> s2 >> s3;
    n = s1.size();
    m = s2.size();
    c = s3.size();
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= c; k++)
            {
                ans = max(ans, rec(i, j, k));
            }
        }
    }
    cout << ans << "\n";
}
int main()
{

    int t;
    cin >> t;
    while (t--)
        solve();
}