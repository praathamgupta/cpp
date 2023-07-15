#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int equalset(vector<int> &a, vector<vector<int>> &dp, int sum, int n)
{
    for (int i = 1; i < (n + 1); i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 0; j < (sum + 1); j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < (n + 1); i++)
    {
        for (int j = 1; j < (sum + 1); j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = (dp[i - 1][j]) % mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i - 1]]) % mod;
            }
        }
    }
    return dp[n][sum];
}

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        sum = sum + a[i];
    }
    if (sum % 2 != 0)
    {
        cout << "0\n";
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    int result = equalset(a, dp, sum, n);
    cout << result % mod << "\n";
}

signed main()
{
    solve();
}
