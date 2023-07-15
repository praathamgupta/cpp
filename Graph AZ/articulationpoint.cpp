#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<vector<int>> g;
vector<int> vis;
vector<int> low;
vector<int> disc;
vector<int> parent;
vector<bool> articulationPoints;

void dfs(int node)
{
    static int time = 0;
    int children = 0;
    vis[node] = 1;
    disc[node] = low[node] = ++time;

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            children++;
            parent[v] = node;
            dfs(v);

            low[node] = min(low[node], low[v]);

            // Check if the current node is an articulation point
            if (parent[node] == -1 && children > 1)
                articulationPoints[node] = true;
            if (parent[node] != -1 && low[v] >= disc[node])
                articulationPoints[node] = true;
        }
        else if (v != parent[node])
        {
            low[node] = min(low[node], disc[v]);
        }
    }
}

void solve()
{
    cin >> n >> m >> q;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    low.assign(n + 1, 0);
    disc.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    articulationPoints.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (articulationPoints[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        g.clear();
        vis.clear();
        low.clear();
        disc.clear();
        parent.clear();
        articulationPoints.clear();
    }
    return 0;
}
