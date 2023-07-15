#include <bits/stdc++.h>
using namespace std;
int n, weight;
int dp[1000][1000];

int knapsack(int n, int weight, int wt[], int v[])
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= weight; j++)
        {
            if (i == 0 || j == 0)
            {
                return 0;
            }
            else if (wt[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max((dp[i - 1][j]), v[i - 1] + (j - wt[i - 1]));
            }
        }
    }
    return dp[n][weight];
}
void solve()
{
    cin >> n >> weight;
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