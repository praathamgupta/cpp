#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
using lli = long long int;
const lli mod = 1000000007;
 
lli knapsack(lli n, lli w, const vector<lli>& item, const vector<lli>& prices, vector<vector<lli>>& dp)
{
    for (lli i = 1; i < n + 1; i++)
    {
        for (lli j = 1; j < w + 1; j++)
        {
            if (item[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], prices[i - 1] + dp[i - 1][j - item[i - 1]]);
            }
        }
    }
    return dp[n][w];
}
 
void solve()
{
    lli n, w;
    cin >> n >> w;
    vector<lli> item(n);
    vector<lli> prices(n);
    vector<vector<lli>> dp(n + 1, vector<lli>(w + 1, 0));
 
    for (lli i = 0; i < n; i++)
    {
        cin >> item[i] >> prices[i];
    }
 
    cout << knapsack(n, w, item, prices, dp);
}
 
int main()
{
    solve();
    return 0;
}