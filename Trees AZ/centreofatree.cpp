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
    }
    dfs(maxchild, 0, 0);
    maxchild = 1;
    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxchild])
        {
            maxchild = j;
        }
    }

    if (dep[maxchild] % 2 != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int temp = maxchild;
        for (int i = 0; i < (dep[maxchild] / 2); i++)
        {
            temp = par[temp];
        }
        cout << temp << endl;
    }
    /*If the depth of maxchild is even, the code proceeds to find the center.
    It initializes a temporary variable temp with the value of maxchild.
    Then, in a loop, it moves temp up the tree by dep[maxchild] / 2 steps.
    This effectively moves temp to the node that is at the middle of the path from node 1 to maxchild.
    Since the path has an even length, moving halfway up the path will lead to one of the centers.
    At the end of the loop, the code prints the value of temp, which represents one of the centers of the tree.*/
    // cout << dep[maxchild];
}

int main()
{
    solve();
    return 0;
}
