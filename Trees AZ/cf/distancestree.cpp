#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> g[50001];
int dep[50001];
int par[50001];
int n, k;
int ans = 0;

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
        }
    }
}

int findDistance(int node1, int node2)
{
    // Finding the Lowest Common Ancestor (LCA) of the two nodes
    while (dep[node1] > dep[node2])
    {
        node1 = par[node1];
    }
    while (dep[node2] > dep[node1])
    {
        node2 = par[node2];
    }
    while (node1 != node2)
    {
        node1 = par[node1];
        node2 = par[node2];
    }
    int lca = node1;

    // Calculating the distance between node1 and node2
    int distance = dep[node1] + dep[node2] - 2 * dep[lca];
    return distance;
}

void solve()
{
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

signed main()
{
    solve();
    return 0;
}
