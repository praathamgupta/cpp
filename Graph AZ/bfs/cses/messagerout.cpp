// bfs

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
vector<vector<int>> g(200020);
lli n, m;
lli dist[200020];
lli par[200020];
void bfs(lli st)
{
    for (lli i = 1; i < n + 1; i++)
    {
        dist[i] = 1e9;
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
            if (dist[cur] + 1 < dist[v])
            {
                dist[v] = dist[cur] + 1;
                par[v] = cur;
                q.push(v);
            }
        }
    }
}
void solve()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    lli st = 1;
    lli en = n;
    bfs(st);
    if(dist[en]!=1e9){
    lli temp = en;
    vector<lli> path;
    while (temp != st)
    {
        path.push_back(temp);
        temp = par[temp];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());

    cout << dist[en] + 1 << "\n";
    for (auto x : path)
    {
        cout << x << " ";
    }}
    else{
        cout<<"IMPOSSIBLE";
    }
}
int main()
{
    solve();
}