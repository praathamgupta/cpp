#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ii pair<int, int>
#define f first
#define s second
#define int long long
int n, m;
vector<vector<ii>> g;
vector<int> dist;
vector<int> vis;

void dij(int st)
{
    dist[st] = 0;

    priority_queue<ii> pq;
    pq.push({0, st});

    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();

        int dis = -top.f;
        int node = top.s;
        if (vis[node])
        {
            continue;
        }
        vis[node] = 1;

        for (auto v : g[node])
        {
            int neigh = v.f;
            int weigh = v.s;

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
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    dist.assign(n + 1, 1e18);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dij(1);

    if (dist[n] != 1e18)
        for (int i = 1; i < n + 1; i++)
        {
            cout << dist[i] << " ";
        }

    else
        cout << "-1" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}