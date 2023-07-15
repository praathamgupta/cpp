#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int n, m;
vector<bool> vis;
bool bipart;
vector<int> color;
bool bfs(int start, vector<int> &color, vector<vector<int>> &graph)
{

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        for (auto it : graph[node])
        {

            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }

    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (!bfs(i, color, graph))
            return false;
    }

    return true;
}
void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    color.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (isBipartite(g))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    solve();
}