#include <bits/stdc++.h>
using namespace std;
vector<int> g[100100];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int numChid[100100];
int subtreesz[100100];
void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    subtreesz[node] = 1;
    numChid[node] = 0;
    for (auto v : g[node])
    {
        if (v != parent)
        { // if not the parent then it is the childs
            numChid[node]++;
            dfs(v, node, depth + 1);
            subtreesz[node] += subtreesz[v];
        }
    }
    if (numChid[node] == 0)
    {
        isLeaf[node] = 1;
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a); // trees are always undirected
    }
    dfs(1, 0, 0);
}