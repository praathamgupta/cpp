#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli dis[501][501];
void solve()
{
    lli n, m, q;
    cin >> n >> m >> q;
    for (lli i = 0; i < (n + 1); i++)
    {
        for (lli j = 0; j < (n + 1); j++)
        {
            if (i != j)
            {
                dis[i][j] = 1e18;
            }
        }
    }
    for (lli i = 0; i < m; i++)
    {
        lli a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }

    for (lli k = 0; k < (n + 1); k++)
    {
        for (lli i = 0; i < (n + 1); i++)
        {
            for (lli j = 0; j < (n + 1); j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--)
    {
        lli x, y;
        cin >> x >> y;
        if (dis[x][y] == 1e18)
        {
            cout << "-1\n";
        }
        else
        {
            cout << dis[x][y] << "\n";
        }
    }
}
int main(){
    solve();
}