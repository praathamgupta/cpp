#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1000000007;

void solve()
{
    int n;
    cin >> n;

    vector<vector<bool>> grid(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                grid[i][j] = false;
            }
            else
            {
                grid[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int op1 = 0, op2 = 0;
                    if (i >= 1)
                    {
                        op1 = dp[i - 1][j];
                    }
                    if (j >= 1)
                    {
                        op2 = dp[i][j - 1];
                    }

                    dp[i][j] = (op1 + op2) % mod;
                }
            }
        }
    }

    cout << dp[n - 1][n - 1] % mod;
}

signed main()
{
    solve();
    return 0;
}
