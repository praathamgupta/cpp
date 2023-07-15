#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#define endl '\n'
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using ld = long double;
const lli mod = 1e9 + 7;

int n, m;
vector<vector<int>> g;
vector<int> dist;
int min_cycle;

void bfs(int sc)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e9;
    }

    dist[sc] = 0;
    queue<int> q;
    q.push(sc);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto v : g[cur])
        {
            if (dist[v] == 1e9)
            {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
            else if (dist[v] >= dist[cur])
            {
                min_cycle = min(min_cycle, dist[cur] + dist[v] + 1);
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    g.resize(n + 1);
    dist.resize(n + 1);

    min_cycle = 1e9;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }

    if (min_cycle == 1e9)
        cout << -1 << endl;
    else
        cout << min_cycle << endl;
}

signed main()
{
    IOS

    // int T; cin >> T; while(T--)
    solve();
}