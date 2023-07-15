#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
#define mod 1000000007
int n, m;
vector<vector<ii>> g;
vector<int> num;
vector<int> dist;
void dij(int st)
{
    dist[st] = 0;
    num[st] = 1;
    priority_queue<ii> pq;
    pq.push({0, st});
    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();
        int dis = -top.f;
        int node = top.s;
        for (auto v : g[node])
        {
            int neigh = v.f;
            int weigh = v.s;
            if (dist[neigh] > dis + weigh)
            {
                dist[neigh] = dis + weigh;
                num[neigh] = num[node];
                pq.push({-dist[neigh], neigh});
            }
            else if (dist[neigh] == dis + weigh)
            {
                num[neigh] = (num[neigh] + num[node]) % mod;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);

    dist.assign(n + 1, 1e18);
    num.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v ;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    dij(1);
    if (dist[n] != 1e18)
    {
        cout << num[n] % mod << "\n";
    }
    else
    {
        cout << "0\n";
    }
}
signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}