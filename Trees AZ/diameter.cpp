#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int par[200005];
int dep[200005];

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
    int maxchild = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxchild])
        {
            maxchild = j;
        }
        //It finds the node with the maximum depth by iterating 
        //from node 2 to n and 
        //updating maxchild whenever a node with a greater 
        //depth is encountered.
    }
    dfs(maxchild, 0, 0);
    maxchild = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxchild])
        {
            maxchild = j;
        }
        //It performs a second depth-first search from the node with the 
        //maximum depth to recompute the depths and parents. 
        //This is done to find the node 
        //with the maximum depth from the previously 
        //identified deepest node.
    }
    cout << dep[maxchild];
}

int main()
{
    solve();
    return 0;
}
