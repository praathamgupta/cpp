#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1000][1000];
string s1, s2;
int rec(int i, int j)
{
    if (i == s1.length() && j == s2.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (s1[i] == s2[j])
    {
        ans =  max(ans, 1+ rec(i + 1, j + 1));
    }
    return dp[i][j] = ans;
}
void solve()
{
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j));
        }
    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}