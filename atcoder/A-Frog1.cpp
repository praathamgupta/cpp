#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
int dp[100001];
int height[100001];

lli jump(lli i)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    lli cost = 1e9;
    cost = min(cost, (jump(i - 1) + abs(height[i] - height[i - 1])));
    if (i > 1)
    {
        cost = min(cost, (jump(i - 2) + abs(height[i] - height[i - 2])));
    }
    dp[i] = cost;
    return cost;
}

void solve()
{
    memset(dp, -1, sizeof(dp));

    lli n;
    cin >> n;
    for (lli i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << jump(n - 1) << "\n";
}

int main()
{
    solve();
    return 0;
}
