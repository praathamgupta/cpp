#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s, e;
vector<int> dist;
vector<vector<int>> g;
vector<vector<int>> paths;
vector<int> currentPath;

void dfs(int node)
{
    currentPath.push_back(node);

    if (node == e)
    {
        paths.push_back(currentPath);
    }
    else
    {
        for (auto v : g[node])
        {
            if (dist[v] == dist[node] + 1)
            {
                dfs(v);
            }
        }
    }

    currentPath.pop_back();
}

void solve()
{
    cin >> n >> m >> s >> e;
    g.clear();
    dist.clear();
    paths.clear();
    currentPath.clear();
    g.resize(n + 1);
    dist.resize(n + 1);
    dist.assign(n + 1, 1e18);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur])
        {
            if (dist[cur] + 1 < dist[v])
            {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
        }
    }

    if (dist[e] == 1e18)
    {
        // cout << "No path from " << s << " to " << e << endl;
        cout << "-1\n";
        return;
    }

    dfs(s);
    set<int> st;
    // cout << "Shortest distance from " << s << " to " << e << ": " << dist[e] << endl;

    // cout << "All possible shortest paths from " << s << " to " << e << ":" << endl;
    for (const auto &path : paths)
    {
        for (int i = 0; i < path.size(); i++)
        {
            st.insert(path[i]);
        }
        // cout << endl;
    }
    cout << st.size()<<"\n";
}

signed main()
{
    int t;cin>>t;while(t--)
    solve();
}
