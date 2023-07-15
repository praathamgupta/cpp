#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

lli dp[101][101];




void solve()
{
    lli n, m, k;
    cin >> n >> m >> k;
    vector<vector<lli>> g(101,vector<lli>(101,-1));
    for (lli i = 0; i < n/2; i++)
    {
        for (lli j = 0; j < n/2; j++)
        {
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
   
}

int main()
{
    solve();
    return 0;
}
