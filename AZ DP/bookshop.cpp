#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int dp[n + 1][x + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int money = 0; money <= x; money++)
        {
            if (money == 0 || i == 0)
            {
                dp[i][money] = 0;
            }
            else
            {
                int op1 = (i == 1) ? 0 : dp[i - 1][money];
                int op2 = (money < b[i]) ? 0 : dp[i - 1][money - b[i]] + p[i];
                dp[i][money] = max(op1, op2);
            }
        }
    }
    cout << dp[n][x] << "\n";
}
int main()
{
    solve();
}