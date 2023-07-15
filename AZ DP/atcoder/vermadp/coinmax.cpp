#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int maxcoin(vector<int> a, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }
    if (a[n - 1] > sum)
    {
        return dp[n][sum] = maxcoin(a, n - 1, sum);
    }
    else if (a[n - 1] <= sum)
    {
        return dp[n][sum] = maxcoin(a, n - 1, sum) + maxcoin(a, n, sum - a[n - 1]);
    }
    return 0; // Added default return statement
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
    memset(dp, -1, sizeof(dp));
    cout << maxcoin(a, n, sum);
}

int main()
{
    solve();
}
