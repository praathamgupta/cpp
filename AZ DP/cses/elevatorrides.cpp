#include <bits/stdc++.h>
using namespace std;
#define int long long

int minimumRides(int maxweight, int n, vector<vector<int>> &dp, vector<int> &weight)
{
    if (n == 0 || maxweight == 0)
    {
        return 0;
    }
    if (dp[n][maxweight] != -1)
    {
        return dp[n][maxweight];
    }
    if (weight[n - 1] > maxweight)
    {
        dp[n][maxweight] = minimumRides(maxweight, n - 1, dp, weight);
    }
    else
    {
        dp[n][maxweight] = max(minimumRides(maxweight, n - 1, dp, weight), 1 + minimumRides(maxweight - weight[n - 1], n - 1, dp, weight));
    }
    return dp[n][maxweight];
}

void solve()
{
    int n, maxweight;
    cin >> n >> maxweight;
    vector<int> weight(n);
    vector<vector<int>> dp(n + 1, vector<int>(maxweight + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int rides = minimumRides(maxweight, n, dp, weight);
    cout << rides << "\n";
}

signed main()
{
    solve();
}
