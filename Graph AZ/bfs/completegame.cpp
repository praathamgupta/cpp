#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g,backedge;
vector<int> indeg;
vector<int> topo;
int n,m,mod = 1e9+7;
void kahn()
{
    queue<int> q;
    for (int i = 1; i < (n + 1); i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
}
void solve()
{

    cin >> n >> m;
    g.resize(n + 1);
    backedge.resize(n+1);
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        backedge[b].push_back(a);
        indeg[b]++;
    }

    kahn();

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int node : topo)
    {
        for (auto v : backedge[node])
        {
            dp[node] = (dp[node] + dp[v])%mod;
        }
    }

    cout << dp[n] %mod<< "\n";
}
signed main()
{
    solve();
}