#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define F first
#define S second
#define int long long
int n, m, k;
vector<vector<ii>> g;
vector<int> dist;
vector<int> vis;
vector<int> final;
void dij(int st)
{
    dist[st] = 0;
    priority_queue<ii> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();
        int dis = -top.F;
        int node = top.S;
        if (vis[node])
        {
            continue;
        }
        vis[node] = 1;
        for (auto v : g[node])
        {
            int neigh = v.F;
            int weigh = v.S;
            if (dist[neigh] > dis + weigh)
            {
                dist[neigh] = dis + weigh;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    g.clear();
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    dist.assign(n + 1, 1e18);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dij(1);
    if (dist[n] != 1e18)
    {
        //  final.push_back(dist[n]);
        cout << dist[n] << " ";
    }
    sort(final.begin(), final.end());
    for (auto x : final)
    {
        //   cout<<x<<" ";
    }
}
signed main()
{
    solve();
}