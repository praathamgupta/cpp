#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int mincoins(vector<int> &dp, int n, int sum, vector<int> &a)
{
    if (sum == 0)
    {
        return 0;
    }
    if (sum < 0)
    {
        return INT64_MAX;
    }
    if (dp[sum] != -1)
    {
        return dp[sum];
    }
    int mini = INT64_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = mincoins(dp, n, sum - a[i], a);
        if (ans != INT64_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }
    return dp[sum] = mini;
}
void solve()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(sum + 1, -1);
    int x = mincoins(dp, n, sum, a);
    if (x == INT64_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << x << "\n";
    }
}

signed main()
{
    solve();
}
