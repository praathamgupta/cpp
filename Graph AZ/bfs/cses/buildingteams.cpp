#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> col;
vector<int> visited;
bool bipartite = true;

void color(int node, int cur_col)
{
    if (col[node] != -1 && col[node] != cur_col)
    {
        bipartite = false;
        return;
    }
    col[node] = cur_col;
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    for (auto v : g[node])
    {
        color(v, cur_col ^ 1);
    }
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, -1);
    visited.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            color(i, 0);
        }
    }

    if (bipartite)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << (col[i] + 1) << " "; // Print team number (1 or 2)
        }
    }
    else
    {
        cout << "IMPOSSIBLE"; // Graph is not bipartite
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
