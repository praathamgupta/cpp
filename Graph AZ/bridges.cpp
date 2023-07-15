// tarjan theorem
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<int> tin;
vector<int> low;
int timer;
vector<pair<int, int>> bridges;

void dfs(int node, int parent = -1)
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (auto v : g[node])
    {
        if (v == parent)
            continue;

        if (vis[v])
            low[node] = min(low[node], tin[v]);
        else
        {
            dfs(v, node);
            low[node] = min(low[node], low[v]);

            if (low[v] > tin[node])
                bridges.push_back({node, v});
        }
    }
}

void findBridges()
{
    bridges.clear();
    timer = 0;
    vis.assign(n + 1, 0);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    findBridges();
    cout << bridges.size();
    //  cout << "Bridges:\n";
    for (auto bridge : bridges)
    {
        //  cout << bridge.first << " - " << bridge.second << "\n";
    }
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    g.clear();
    vis.clear();
    tin.clear();
    low.clear();
    //}
    // return 0;
}
