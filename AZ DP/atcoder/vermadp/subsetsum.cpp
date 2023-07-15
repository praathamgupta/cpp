#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int subsetsum(int n, vector<int> a, int sum)
{
    if (n <= 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (dp[n][sum] != -1)
    {
        return (dp[n][sum]);
    }
    if (a[n - 1] > sum)
    {
        return dp[n][sum] = subsetsum(n - 1, a, sum);
    }
    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = (subsetsum(n - 1, a, sum - a[n - 1]) || subsetsum(n - 1, a, sum));
    }
}
void printsubset(int n, vector<int> a, int sum)
{
    if (sum == 0)
    {
        return;
    }
    if (n <= 0)
    {
        return;
    }
    if (dp[n][sum])
    {
        if (dp[n - 1][sum])
        {
            printsubset(n - 1, a, sum);
        }
        else
        {
            printsubset(n - 1, a, sum - a[n - 1]);
            cout << a[n - 1] << " ";
        }
    }
    else
    {
        printsubset(n - 1, a, sum);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum;
    cin >> sum;
    if (subsetsum(n, a, sum))
    {
        cout << "YES";
        printsubset(n, a, sum);
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
    solve();
}