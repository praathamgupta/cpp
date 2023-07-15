#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int dp[1000100][4];
int n;
int rec(int index, int match)
{
    if (index == n)
        return 1;
    if (dp[n - index][match] != -1)
        return dp[n - index][match];
    if (match == 0)
    {
        return dp[n - index][match] = (rec(index + 1, 1) % mod + rec(index + 1, 0) % mod) % mod;
    }
    else if (match == 1)
    {
        return dp[n - index][match] = (rec(index + 1, 2) % mod + rec(index + 1, 1) % mod) % mod;
    }
    else if (match == 2)
    {
        return dp[n - index][match] = (rec(index + 1, 3) % mod + rec(index + 1, 0) % mod) % mod;
    }
    else
    {
        return dp[n - index][match] = rec(index + 1, 2) % mod;
    }
}
void solve()
{
    cin >> n;
    cout << rec(0, 0) << '\n';
}
signed main()
{
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        solve();
    }
    return 0;
}