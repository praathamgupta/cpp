#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
vector<lli> dp(1000001, -1);
lli jump(lli i, vector<lli> &height, lli c)
{
    lli z = height.size();

    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    lli cost = 1e9;
    for (lli x = 1; x <z + 1; x++)
    {
        if (i >= x)
        {
            cost = min(cost, jump(i - x, height, c) + c + (height[i] - height[i - x]) * (height[i] - height[i - x]));
        }
    }
    return dp[i] = cost;
}
void solve()
{
    lli n, c;
    cin >> n >> c;
    vector<lli> height(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << jump(n - 1, height, c);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}