#include <bits/stdc++.h>
using namespace std;
#define int long long int
int height[100001];
int dp[100001];
int jump(int i, int k)
{
    if (i == 0 || k == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int cost = 1e9;
    for (int x = 1; x <= k; x++)
    {
        if (i >= x)
        {
            cost = min(cost, (jump(i - x, k)) + abs(height[i] - height[i - x]));
        }
    }
    return dp[i] = cost;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << jump(n - 1, k) << "\n";
}
signed main()
{
    solve();
}