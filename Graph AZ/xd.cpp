#include <bits/stdc++.h>
using namespace std;
#define int long long
using ii = pair<int, int>;
#define F first
#define S second
const int mod = 1000000007;
const int INF = 1e18;

vector<vector<ii>> g; // g[a] -> pair(dist,j) i->j node with distance dist
vector<int> dist;
vector<int> vis;
vector<int> paths;    // paths[i] = no. of cheapest paths from start to ith node
vector<int> min_node; // nodes[i] = min. no. of nodes int the path from st to i
vector<int> max_node;

void dijkstra(int st)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, st});
    dist[st] = 0;
    paths[st] = 1;
    min_node[st] = 1;
    max_node[st] = 1;

    while (!pq.empty())
    {
        ii cur = pq.top();
        pq.pop();

        if (vis[cur.S])
            continue;

        vis[cur.S] = 1; // we will mark vis 1 when its neighbours are already explored
        for (auto v : g[cur.S])
        {
            int neigh = v.S;
            int wt = v.F;

            if (dist[neigh] > dist[cur.S] + wt)
            {
                dist[neigh] = dist[cur.S] + wt;
                paths[neigh] = (paths[cur.S] % mod);
                min_node[neigh] = min_node[cur.S] + 1;
                max_node[neigh] = max_node[cur.S] + 1;
                pq.push({dist[neigh], neigh});
            }
            else if (dist[neigh] == dist[cur.S] + wt)
            {
                paths[neigh] += paths[cur.S];
                paths[neigh] = (paths[neigh] % mod);
                min_node[neigh] = min(min_node[neigh], min_node[cur.S] + 1);
                max_node[neigh] = max(max_node[neigh], max_node[cur.S] + 1);
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    dist.assign(n + 1, INF);
    vis.assign(n + 1, 0);
    paths.assign(n + 1, 0);
    min_node.assign(n + 1, INF);
    max_node.assign(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back({c, b});
    }
    dijkstra(1);
    if (dist[n] != INF)
    {
        cout << dist[n] << ' ' << paths[n] << ' ' << min_node[n] - 1 << ' ' << max_node[n] - 1 << '\n';
    }
    else
        cout << "-1\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}