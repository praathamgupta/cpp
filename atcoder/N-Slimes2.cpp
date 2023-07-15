#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

lli dp[401][401];
vector<lli> a;
vector<lli> p;
lli n;

lli slimes(lli l, lli r)
{
    if (l == r)
    {
        return 0;
    }
    if (dp[l][r] == -1)
    {
        lli ans = INT64_MAX;
        for (lli k = l; k < r; k++)
        {
            lli cost = slimes(l, k) + slimes(k + 1, r) + p[r + 1] - p[l];
            ans = min(ans, cost);
        }
        dp[l][r] = ans;
    }
    return dp[l][r];
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.resize(n);
    p.resize(n + 1);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    p[0] = 0;
    for (lli i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i - 1];
    }
    cout << slimes(0, n - 1) << "\n";
}

int main()
{
    solve();
    return 0;
}
