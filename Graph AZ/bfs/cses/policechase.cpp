#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
int n, m;
vector<int> vis;
vector<int> path;
vector<vector<int>> allPaths;

void dfs(int node)
{
    vis[node] = 1;
    path.push_back(node);
    if (node == n) // If the current node is the destination node n
    {
        allPaths.push_back(path); // Add the current path to the list of all paths
    }
    else
    {
        for (auto v : g[node])
        {
            if (!vis[v])
            {
                dfs(v);
            }
        }
    }
    // Backtrack by removing the current node from the path
    path.pop_back();
    vis[node] = 0; // Reset the visited status to allow other paths to include this node
}

void solve()
{
    cin >> n >> m;
    g.clear();
    vis.clear();
    vis.resize(n + 1, 0);
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    
    // Print all paths
    for (const auto& path : allPaths)
    {
        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

signed main()
{
    solve();
}
