#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
void solve()
{
    lli n, x;
    cin >> n >> x;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<lli> dp(x + 1, 0);
    dp[0] = 1;
    for (lli i = 1; i <= x; i++)
    {
        dp[i] = 0;
        for (lli coin : a)
        {
            if (coin <= i)

                dp[i] += (dp[i - coin]) % mod;
        }
    }
    cout << (dp[x] % mod);
}
int main()
{
    solve();
}