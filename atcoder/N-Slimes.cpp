#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli mergeelements(lli l, lli r, vector<vector<lli>> &dp, vector<lli> &p, vector<lli> &a)
{
    if (l == r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    lli ans = INT64_MAX;
    for (lli k = l; k < r; k++)
    {
        ans = min(ans, mergeelements(l, k, dp, p, a) + mergeelements(k + 1, r, dp, p, a) + (p[k + 1] - p[l]) + (p[r + 1] - p[k + 1]));
    }
    return dp[l][r] = ans;
}
void solve()
{
    lli n;
    cin >> n;
    vector<lli> a(n);
    vector<lli> p(n + 1);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    p[0] = a[0];
    for (lli i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i - 1];
    }
    vector<vector<lli>> dp(n + 1, vector<lli>(n + 1, -1));
    cout << mergeelements(0, n - 1, dp, p, a);
}
int main()
{

    solve();
}