#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
bool grid[1001][1001];
lli dp[1001][1001];
void solve()
{
    lli n, m;
    cin >> n >> m;
    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
            {
                grid[i][j] = 0;
            }
            else
            {
                grid[i][j] = 1;
            }
        }
    }
    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {

            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                lli op1 = 0;
                lli op2 = 0;
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
            if (grid[i][j])
            {
                dp[i][j] = 0;
            }
        }
    }
    if (grid[n - 1][m - 1])
    {
        cout << "0\n";
    }
    cout << dp[n - 1][m - 1] << "\n";
}
int main()
{
    solve();
}