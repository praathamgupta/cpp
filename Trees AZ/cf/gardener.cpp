#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> par;
vector<int> dep;
vector<int> numchild;

int cnt = 0; // Counter to store the number of leaf nodes

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;

    bool isLeaf = true; // Flag to check if the current node is a leaf node

    for (auto v : g[node])
    {
        if (v != parent)
        {
            isLeaf = false; // The node has at least one child, so it's not a leaf
            numchild[node]++;
            dfs(v, node, depth + 1);
        }
    }

    if (isLeaf)
    {
        cnt++; // Increment the leaf node count
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    g.resize(n + 1);
    par.resize(n + 1);
    dep.resize(n + 1);
    numchild.resize(n + 1);

    for (int i = 0; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0); // Assuming the root node is 1

    // cout << cnt << endl; // Output the number of leaf nodes
   cout<<(n-cnt)<<"\n";
}

signed main()
{
    solve();
}
