#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define f first
#define s second
vector<vector<ii>> g;
vector<int> dist;

int n, m;
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
        for (auto v : g[node])
        {
            int neigh = v.f;
            int weigh = v.s;
            if (dist[neigh] > (dis + weigh))
            {
                dist[neigh] = (dis + weigh);
                pq.push({-dist[neigh], neigh});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.clear();
    dist.clear();
    dist.resize(n + 1);
    dist.assign(n + 1, 1e18);
    g.resize(n + 1);

    int maxC = INT_MIN; // Initialize maxC to the minimum value possible

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});

        maxC = max(maxC, c); // Update maxC if c is greater
    }

    bool isMaxCFound = false; // Flag to indicate if the maximum value of c is found

    for (int i = 0; i < g[1].size(); i++)
    {
        if (g[1][i].s == maxC && !isMaxCFound)
        {
            g[1][i].s /= 2; // Divide maxC by 2
            isMaxCFound = true; // Set the flag to true after halving maxC
        }
    }

    dij(1);
    if (dist[n] != 1e18)
    {
        cout << dist[n] << "\n";
    }
}
signed main()
{
    solve();
}
