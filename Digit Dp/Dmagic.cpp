#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl '\n'
#define int long long

int m, D;
string A, B;
int len;
int dp[2002][2][2][2001][2];
const int mod = 1e9 + 7;

int rec(int level, int tlo, int thi, int rem, int pos)
{
    if (level == len)
    {
        if (rem == 0)
            return 1;
        else
            return 0;
    }
    if (dp[level][tlo][thi][rem][pos] != -1)
        return dp[level][tlo][thi][rem][pos];
    int ans = 0;
    int lo = 0;
    if (tlo == 1)
    {
        lo = A[level] - '0';
    }
    int hi = 9;
    if (thi == 1)
    {
        hi = B[level] - '0';
    }
    for (int i = lo; i <= hi; i++)
    {
        int ntlo = 0;
        int nthi = 0;
        if (tlo == 1 && i == lo)
            ntlo = 1;
        if (thi == 1 && i == hi)
            nthi = 1;
        if ((pos == 1 && i != D))
        {
            ans = (ans + rec(level + 1, ntlo, nthi, (rem * 10 + i) % m, 1 - pos)) % mod;
            ans %= mod;
            // cout<<level<<":"<<i<<"->"<<ntlo<<":"<<nthi<<endl;
        }
        if (pos == 0 && i == D)
        {
            ans = (ans + rec(level + 1, ntlo, nthi, (rem * 10 + i) % m, 1 - pos)) % mod;
            ans %= mod;
            // cout<<level<<":"<<i<<endl;
        }
    }
    return dp[level][tlo][thi][rem][pos] = ans;
}

void solve()
{
    cin >> m >> D;
    cin >> A >> B;
    len = A.length();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0, 1) % mod << endl;
}
signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}