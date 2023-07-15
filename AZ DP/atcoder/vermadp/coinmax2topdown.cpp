#include <bits/stdc++.h>
using namespace std;
using lli = long long;
const lli mod = 1e9 + 7;
int dp[101][1000001];
void solve()
{
    int n,sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
   for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
        dp[i][j] = 0;
    }
}

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= (n); i++)
    {
        for (int j = 1; j <= (sum); j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j] % mod;
            }
            else
            {
                dp[i][j] = dp[i - 1][j] % mod + dp[i][j - a[i - 1]] % mod;
            }
        }
    }
    cout << dp[n][sum] % mod << "\n";
}
signed main()
{
    solve();
}