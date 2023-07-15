#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<lli> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            dp[i][sum] = dp[i - 1][sum];
            if (sum - a[i - 1] >= 0)
                dp[i][sum] = (dp[i][sum] + dp[i][sum - a[i - 1]]) % mod;
        }
    }
    cout << dp[n][x];
}

int main()
{
    solve();
    return 0;
}
