#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int countofsubsetsum(int n, vector<int> &a, int sum)
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
        return dp[n][sum] = countofsubsetsum(n - 1, a, sum);
    }
    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = countofsubsetsum(n - 1, a, sum - a[n - 1]) + countofsubsetsum(n - 1, a, sum);
    }
    return 0;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int diff;
    cin >> diff;
    int sum = 0;
    memset(dp, -1, sizeof(dp));
    cout << countofsubsetsum(n, a, diff);
}
int main()
{

    solve();
}