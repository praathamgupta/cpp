#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int countofsubsetsum(vector<int> &a, int n, int sum)
{

    if (sum == 0) // isko pehle rkhna hai as the base case tmkc
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
        return dp[n][sum] = countofsubsetsum(a, n - 1, sum);
    }
    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = countofsubsetsum(a, n - 1, sum - a[n - 1]) + countofsubsetsum(a, n - 1, sum);
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
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    cout << countofsubsetsum(a, n, sum) << "\n";
}
int main()
{
    solve();
    return 0;
}