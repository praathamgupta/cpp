#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n, m;
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
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++; // indeg ka input hai
    }
    kahn();
    for (auto x : topo)
    {
        cout << x << " ";
    }
}
signed main()
{
    solve();
}