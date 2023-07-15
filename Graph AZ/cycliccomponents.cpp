#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
using lli = long long;

void dfs(lli node, vector<lli> &temp, vector<vector<lli>> &g, vector<lli> &vis)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, temp, g, vis);
        }
    }
}

void solve()
{
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> g(n + 1);
    vector<lli> deg(n + 1, 0);

    for (lli i = 0; i < m; i++)
    {
        lli x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++; // find the degree of each node in the graph
        deg[y]++;
    }
    lli cnt = 0;
    vector<lli> vis(n + 1, 0);
    vector<lli> vertex;
    for (lli i = 1; i <= (n); i++)
    {

        vertex.clear();
        if (!vis[i])
        {
            // vertex.clear();
            dfs(i, vertex, g, vis);
            bool ans = 1;
            for (auto v1 : vertex)
            {
                if (deg[v1] != 2)
                {
                    ans = 0;
                    break;
                }
            }
            if (ans)
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}