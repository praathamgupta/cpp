#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> indeg;
vector<int> topo;
int n, m;

void kahn()
{
    priority_queue<int> pq;
    for (int i = 1; i < (n + 1); i++)
    {
        if (indeg[i] == 0)
        {
            pq.push(-i);
        }
    }

    while (!pq.empty())
    {
        int cur = -pq.top();
        pq.pop();
        topo.push_back(cur);

        for (auto v : g[cur])
        {
            indeg[v]--;
            if (indeg[v] == 0)
            {
                pq.push(-v);
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
        indeg[b]++;
    }

    kahn();

    if (topo.size() != n)
    {
        cout << -1 << endl;   // mtlb yaha cycle hai
        return;
    }

    for (auto x : topo)
    {
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    solve();
}