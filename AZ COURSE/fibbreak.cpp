#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )
lli maxsum(lli n, lli sum, vector<lli> &a, vector<vector<lli>>& dp)
{
    if (sum == 0)
        return 0;
    if (n <= 0 || sum < 0)
        return INT_MAX - 1;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    
    if (a[n - 1] <= sum)
        return dp[n][sum] = min(1 + maxsum(n, sum - a[n - 1], a, dp), maxsum(n - 1, sum, a, dp));
    else
        return dp[n][sum] = maxsum(n - 1, sum, a, dp);
}

void solve()
{
    lli k;
    cin >> k;
    vector<lli> a(k);

    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i < k; i++) // Start from i = 2
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    vector<vector<lli>> dp(k + 1, vector<lli>(k + 1, -1));
    cout << maxsum(k, k, a, dp)<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}