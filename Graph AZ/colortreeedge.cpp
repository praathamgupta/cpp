#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> deg;
vector<int>vis;
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
   
        int n, m;
        cin >> n;
        m = n - 1;
        g.resize(n + 1);
        deg.assign(n + 1, 0);
        vis.assign(n+1,0);
        g.resize(n+1);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);

            deg[a]++;
            deg[b]++;
        }

        int maxDeg = 0;
        for (int i = 1; i <= n; i++)
        {
            maxDeg = max(deg[i], maxDeg);
        }

        cout << maxDeg + 1 << "\n";
    
}

int main()
{
    solve();
    return 0;
}
