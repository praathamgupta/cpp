#include <bits/stdc++.h>
using namespace std;
vector<int> g[2000005];
int par[2000005];
int dep[2000005];
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
    for (int i = 0; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int maxchild = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (dep[i] > dep[maxchild])
        {
            maxchild = i;
        }
    }
    /*In this part of the code, the variable maxchild is initialized to 1, 
    assuming that the root node of the tree is labeled as node 1. 
    The loop then iterates from 2 to n+1, where n is the number of nodes in the graph.
   For each iteration of the loop, it compares the depth of
   the current node dep[i] with the depth of the current maximum child node dep[maxchild].
   If the depth of the current node is greater than the depth of the maximum child node,
    the value of maxchild is updated to the current node i.*/
    dfs(maxchild, 0, 0);
    maxchild = 1;
    for (int i = 2; i < n + 1; i++)
    {
        if (dep[i] > dep[maxchild])
        {
            maxchild = i;
        }
    }
    cout << dep[maxchild] << "\n";
}
int main()
{
    solve();
    return 0;
}