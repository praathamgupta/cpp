//https://codeforces.com/contest/464/problem/E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define F first
#define S second
int n, m;
vector<vector<ii>> g;
vector<int> parent;
vector<int> vis;
vector<int> dist;
vector<int> final;
vector<int> xd;
int mod = 1000000007;
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
                parent[neigh] = node;
                pq.push({-dist[neigh], neigh});
                xd.push_back(dist[neigh]);
                reverse(xd.begin(), xd.end());
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
int binpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}
void solve()
{

    cin >> n >> m;
    g.clear();
    g.resize(100001);
    vis.assign(100001, 0);
    dist.assign(100001, 1e18);
    parent.assign(100001, -1);
    final.clear();
    xd.clear();
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, binpow(2, c)});
        g[b].push_back({a, binpow(2, c)});
    }
    int s, t;
    cin >> s >> t;
    dij(s);
    if (dist[n] == 1e18)
    {
        cout << "-1";
    }
    else
    {
        printpath(n);

        cout << xd[0] % mod;
        cout << "\n";
        cout << final.size() << "\n";
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