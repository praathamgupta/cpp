#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ii pair<int, int>
#define f first
#define s second
#define int long long
int n, m;
vector<vector<ii>> g;
vector<int> num;
vector<int> dist;
vector<int> minf;
vector<int> maxf;

void dij(int st)
{
    dist[st] = 0;
    num[st] = 1;
    minf[st] = 0;
    maxf[st] = 0;

    priority_queue<ii> pq;
    pq.push({0, st});

    while (!pq.empty())
    {
        ii top = pq.top();
        pq.pop();
        // While the priority queue is not empty,
        // the top node with the minimum distance is extracted.
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
                // This statement assigns the value of num[node] to num[neigh].
                // It means that the number of shortest paths to the
                // neighbor node neigh
                // is the same as the number of shortest paths to the current node node.
                maxf[neigh] = 1 + maxf[node];
                minf[neigh] = 1 + minf[node];
                pq.push({-dist[neigh], neigh});
            }
            // For each neighbor of the current node, it checks if the
            //  distance can be reduced by going through the current node.
            // If so, it updates the distance, number of shortest paths,
            //  minimum, and maximum destinations to stop at for the neighbor
            //  node.
            else if (dist[neigh] == dis + weigh)
            {
                num[neigh] = (num[neigh] + num[node]) % mod;
                maxf[neigh] = max(1 + maxf[node], maxf[neigh]);
                minf[neigh] = min(1 + minf[node], minf[neigh]);
            }
            // If the distance to the neighbor node is the same as the
            // current distance, it updates the number of shortest paths,
            // minimum, and maximum destinations to stop at for the neighbor node.
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
    minf.assign(n + 1, 1e18);
    maxf.assign(n + 1, 1e18);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }
    dij(1);

    if (dist[n] != 1e18)
        cout << num[n] /*dis from source*/ << " " << num[n] /*no. of shortest path routes*/ << " " << minf[n] /*min number of destination to stop*/ << " " << maxf[n] << endl;
    else
        cout << "0" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}