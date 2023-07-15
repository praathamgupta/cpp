#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
void solve()
{
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT64_MAX-1));
    for (int i = 0; i < (n + 1); i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i < (n + 1); i++)
    {
        for (int j = 1; j < (amount + 1); j++)
        {
            if (coins[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
    dp[n][amount] == INT64_MAX - 1 ? -1 : dp[n][amount];
    cout<<dp[n][amount];
}
signed main()
{
    solve();
}