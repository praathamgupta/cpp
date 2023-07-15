#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> g;
vector<int> dis;

int bfs(int n)
{
    deque<int> dq;
    dq.push_back(1);
    dis[1] = 0;

    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        for (auto v : g[cur])
        {
            int neigh = v.first;
            int weigh = v.second;

            if (dis[neigh] > dis[cur] + weigh)
            {
                dis[neigh] = dis[cur] + weigh;

                if (weigh == 0)
                {
                    dq.push_front(neigh);
                }
                else
                {
                    dq.push_back(neigh);
                }
            }
        }
    }

    return (dis[n] == 1e9 ? -1 : dis[n]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1);
    for (int i = 1; i <= n; i++)
        dis[i] = 1e9;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        if (x == y)
        {
            continue;
        }

        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    cout << bfs(n) << "\n";
    g.clear();
    dis.clear();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    // return 0;
}