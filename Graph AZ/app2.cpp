// undirected graph given with edges and nodes;
// basically wer are given edgelist and we are converting into adjacency list
#include <bits/stdc++.h>
using namespace std;
int n, m,q;
vector<vector<int>> g;

// first vector tells you array position and the next one tells neighbouring position

// if weighted
// vector<vector<pair<int,int>>> g;
vector<int> vis;
vector<pair<int,int>> edgelist;
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
    cin >> n >> q;
    g.resize(n + 1); // resize to number of node
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // from a to b
        // g[a].push_back({b,c}); if weighted
        g[b].push_back(a);
        edgelist.push_back({a,b});
    }
    int num_comp = 0;     //
    for (int i = 0; i <= n; i++)
    {
        if (!vis[i])
        {                               //O(N+M)
            num_comp++;
            dfs(i, num_comp);
        }
    }// 
   // cout<<num_comp;
    vector<int> num_of_edge(num_comp+1);
    for(auto v: edgelist){
        num_of_edge[vis[v.first]];  //visv.first is component number
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        g.clear();
        vis.clear();
    }
    return 0;
}