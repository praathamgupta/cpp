//memoization
#include <bits/stdc++.h>
using namespace std;
int n, weight;
int dp[1000][1000];
int knapsack(int n, int weight, int weighta[], int value[])
{
    if (n == 0 || weight == 0)
    {
        return 0;
    }
    if (dp[n][weight] != -1)
    {
        return dp[n][weight];
    }
    if (weighta[n - 1] > weight)
    {
        return dp[n][weight] = knapsack(n - 1, weight, weighta, value);
    }
    else if (weighta[n - 1] <= weight)
    {
        return dp[n][weight] = max(value[n - 1] + knapsack(n - 1, weight - weighta[n - 1], weighta, value), knapsack(n - 1, weight, weighta, value));
    }
}
void solve()
{
    cin >> n >> weight;
    memset(dp, -1, sizeof(dp));
    int weighta[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weighta[i];
    }
    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << knapsack(n, weight, weighta, value);
}
int main()
{

    solve();
}