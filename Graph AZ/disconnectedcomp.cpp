#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> vis;
int n, m, k;
vector<int> nodes;
vector<pair<int, int>> final;

void dfs(int node, int comp, int &edges)
{
    vis[node] = comp;
    nodes.push_back(node);
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            edges++; // Increment edges count when visiting a new node
            dfs(v, comp, edges);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.clear();
    vis.clear();
    g.resize(n + 1);
    vis.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    int num_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            num_comp++;
            nodes.clear();
            int edges = 0; // Initialize edges count for each component
            dfs(i, num_comp, edges);
            if (vis[i] == num_comp)
            {
                final.push_back({nodes.size(), edges});
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < final.size(); i++)
    {
        int x = final[i].first;
        int y = final[i].second;
        int z = x*(x-1)/2;
        sum += (z-y);
    }
    cout<<sum<<"\n";
}
signed main()
{
    solve();
    return 0;
}
