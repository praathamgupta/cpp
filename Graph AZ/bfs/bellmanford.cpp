#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> dis;
void bell()
{
    dis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int cur = 1; cur <= n; cur++)
        {
            for (auto v : g[cur])
            {
                if (dis[v.first] > dis[cur] + v.second)
                {
                    dis[v.first] = dis[cur] + v.second;
                }
            }
        }
    }
    for (int cur = 1; cur <= n; cur++)
    {
        for (auto v : g[cur])
        {
            if (dis[v.first] > dis[cur] + v.second)
            {
                cout << "-1" << endl;
                return;
            }
        }
    }
    cout << -dis[n] << endl;
}
void solve()
{
    cin >> n;
    cin >> m;
    g.resize(n + 1);
    dis.assign(n + 1, 1e18);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, -c});
    }
    bell();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
