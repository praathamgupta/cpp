#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
lli n, m,k;
lli dist[100100];
vector<vector<pair<lli, lli>>> g;

void bfs(lli st)
{
    for (lli i = 1; i <= n; i++)
    {
        dist[i] = LLONG_MAX;
    }
    dist[st] = 0;
    queue<lli> q;
    q.push(st);
    while (!q.empty())
    {
        lli cur = q.front();
        q.pop();
        for (auto v : g[cur])
        {
            if (dist[cur] + v.second < dist[v.first])
            {   // v.second weight hai
                // dist[cur] represents the current shortest distance from the starting city (st) to the current city (cur).
                dist[v.first] = dist[cur] + v.second;
                q.push(v.first);
            }
        }
    }
}

int main()
{
    cin >> n >> m>>k;
    g.resize(n + 1);
    for (lli i = 0; i < m; i++)
    {
        lli x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
    }
    lli st = 1;
    bfs(st);
    for (int i = 1; i <= n; i++)
    {
       // cout << (dist[i]) << " ";
    }
cout<<dist[n-1]<<"\n";
    return 0;
}
