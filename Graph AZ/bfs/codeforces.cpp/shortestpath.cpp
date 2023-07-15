#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
vector<vector<ii>> g;
vector<int> parent;
vector<int> vis;
vector<int> final;
vector<int> dist;
using tiii = tuple<int, int, int>;
set<tiii> restrictions;
int n, m, k;
#define F first
#define S second
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
            if (dist[neigh] > dis + weigh || (restrictions.count(make_tuple(neigh,weigh,node))>0))
            {
                dist[neigh] = dis + weigh;
                parent[neigh] = node;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}
void printpath(int node)
{
    if (node != 1)
    {
        printpath(parent[node]);
    }
    final.push_back(node);
}
void solve()
{
    cin >> n >> m >> k;
    g.clear();
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    dist.assign(n + 1, 1e18);
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back({b, 1});
        g[b].push_back({a, 1});
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        restrictions.insert(make_tuple(a,b,c));
      //  vis[b]=1;
    }

    dij(1);
    if (dist[n] == 1e18)
    {
        cout << "-1";
    }
    else
    {
        printpath(n);
        for (auto x : final)
        {
            cout << x << " ";
        }
    }
}
signed main()
{
    solve();
}