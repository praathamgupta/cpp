#include <bits/stdc++.h>
using namespace std;
vector<int> depth;
vector<vector<int>> par;
vector<vector<int>> neigh;

void dfs(int node, int prev, int dep)
{
    par[node][0] = prev;
    depth[node] = dep;
    for (int i = 1; i < 20; i++)
    {
        par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto &v : neigh[node])
    {
        if (v != prev)
        {
            dfs(v, node, dep + 1);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--)
    {
        if (depth[u] - depth[v] >= (1 << i))
        {
            u = par[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (par[v][i] != par[u][i])
        {
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[u][0];
}

void solve()
{
    int n;
    cin >> n;
    neigh.clear();
    par.clear();
    depth.clear();
    neigh.resize(n + 1);
    depth.resize(n + 1);
    par.assign(n + 1, vector<int>(20, 0));
    for (int i = 0; i < (n - 1); i++)
    {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }
    dfs(1, 0, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int a = lca(x, y);
        int b = lca(x, z);
        int c = lca(y, z);
        cout << (a ^ b ^ c) << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    // return 0;
}