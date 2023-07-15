#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(200020);
vector<int> dep(200020);
vector<int> par(200020);
int diameter;

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
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    int maxchild = 1; // Initialize maxchild to a valid initial value

    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxchild])
        {
            maxchild = j;
        }
    }

    dfs(maxchild, 0, 0);

    maxchild = 1; // Reset maxchild to 1 before reusing it

    for (int j = 2; j <= n; j++)
    {
        if (dep[j] > dep[maxchild])
        {
            maxchild = j;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dep[i] << " ";
    }
}

int main()
{
    solve();
    return 0;
}
