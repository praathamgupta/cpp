
#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<vector<int>> g;
vector<int> vis;
vector<int>bridges;
void dfs(int node, int comp)
{
    vis[node] = comp;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, comp);
        }
    }
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1); // resize to number of node
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            g[a].push_back(b);
        }
        else
        {
            g[a].push_back(b); // from a to b
            // g[a].push_back({b,c}); if weighted
            g[b].push_back(a);
        }
    }
    int num_comp = 0; //
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        { // O(N+M)
            bridges.push_back(num_comp);
            dfs(i, num_comp);
        }
    } //
   // cout << num_comp-1;
    cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++) {
      cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
}

int main()
{

    solve();
    g.clear();
    vis.clear();

    return 0;
}