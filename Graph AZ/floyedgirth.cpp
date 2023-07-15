#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
lli dis[501][501];

void solve()
{
    lli n, m;
    cin >> n >> m;

    for (lli i = 0; i < n + 1; i++)
    {
        for (lli j = 0; j < n + 1; j++)
        {

            dis[i][j] = (i == j) ? 0 : 1e18; // Initialize to a large value
        }
    }

    for (lli i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;
        dis[a][b] = 1; // Directed edge from a to b
        dis[b][a] = 1;
    }

    for (lli k = 0; k < n + 1; k++)
    {
        for (lli i = 0; i < n + 1; i++)
        {
            for (lli j = 0; j < n + 1; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    lli ans = 1e18;
    for (lli i = 0; i < (n+1); i++)
    {
        ans = min(ans, dis[i][i]);
    }
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
