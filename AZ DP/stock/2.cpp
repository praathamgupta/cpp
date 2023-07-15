#include <bits/stdc++.h>
using namespace std;
#define int long long
int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
{
    int n = prices.size();
    if (index == n)
    {
        return 0;
    }
    if (dp[n][index] != -1)
    {
        return dp[n][index];
    }
    int profit = 0;
    if (buy)
    {
        int buykaro = -prices[index] + solve(index + 1, 0, prices, dp);
        int skipkaro = 0 + solve(index + 1, 1, prices, dp);
        profit = max(buykaro, skipkaro);
    }
    else
    {
        int sellkaro = prices[index] + solve(index + 1, 1, prices, dp);
        int skiparko = 0 + solve(index + 1, 0, prices, dp);
        profit= max(sellkaro,skiparko);
    }
    return dp[n][index]= profit;
}
int maxProfit(vector<int> &prices)
{
    vector<vector<int>>dp(30001,vector<int>(30001,-1));
    solve(0,1,prices,dp);
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
    cout << maxProfit(a);
}
signed main()
{
    solve();
}