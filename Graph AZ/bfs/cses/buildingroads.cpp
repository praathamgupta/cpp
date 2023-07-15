#include <bits/stdc++.h>
using namespace std;
vector<bool>vis(100010,0);
vector<vector<int>> g(100010);
vector<int> bridges;
void dfs(int node)
{
    vis[node] = 1;
    for (auto v : g[node]) // neighbour checking
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i < (n + 1); i++)
    {
        if (!vis[i])
        {
            dfs(i);
            // After the DFS completes for a connected component,
            // the current i is considered a bridge, and
            // it is pushed into the bridges vector.
            bridges.push_back(i);
        }
    }
      cout << bridges.size() - 1 << endl;
    for (int i = 0; i < bridges.size() - 1; i++)
    {
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    }
}
int main()
{
    solve();
}