#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[1001][1001];
int a[1001][1001];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
      for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1e9;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = a[i][j];
            }
            else
            {
                int left = 0;
                int up = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = a[i][j]+ max(up,left);
            }
        }
    }
  cout<<dp[n-1][m-1]<<"\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}