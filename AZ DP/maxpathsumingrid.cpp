#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1001][1001];
bool done[1001][1001];
int a[1001][1001];
int rec(int r, int c)
{
    if (r < 0 || c < 0)
    {
        return -1e9;
    }
    if (r == 0 || c == 0)
    {
        return a[0][0];
    }
    if (done[r][c])
    {
        return dp[r][c];
    }
    int ans = -1e9; // for maximisation -1e9, minimzation 1e9, counting =0
    if (r != 0)
    {
        ans = max(ans, rec(r - 1, c) + a[r][c]);
    }
    if (c != 0)
    {
        ans = max(ans, rec(r, c - 1) + a[r][c]);
    }
    done[r][c] = 1;
    return dp[r][c] = ans;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            done[i][j]=0;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << (rec(n - 1, m - 1)) << "\n";
}
int main()
{
    // int t;cin>>t;while(t--)
    solve();
}