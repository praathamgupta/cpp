#include <bits/stdc++.h>
using namespace std;
using lli = long long;
char grid[1001][1001];
lli dx[] = {1, 0, -1, 0};
lli dy[] = {0, -1, 0, 1};
lli n, m;
#define F first
#define S second
using ii = pair<lli, lli>;
bool inside(lli x, lli y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
lli dist[1001][1001];
ii par[1001][1001];
void bfs(ii st)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 1e9;
        }
    }
    dist[st.F][st.S] = 0;
    queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            lli nx = cur.F + dx[k];
            lli ny = cur.S + dy[k];
            // ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if (inside(nx, ny) && dist[nx][ny] > dist[cur.F][cur.S] + 1)
            {
                dist[nx][ny] = dist[cur.F][cur.S] + 1;
                par[nx][ny] = cur;
                q.push({nx, ny});
            }
        }
    }
}
void solve()
{

    cin >> n >> m;
    ii st, en;
    for (lli i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (lli j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                st = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                en = {i, j};
            }
        }
    }
    bfs(st);
    if (dist[en.F][en.S]!=1e9 && dist[st.F][st.S] != dist[en.F][en.S] )
    {
        cout << "YES\n";
        cout << dist[en.F][en.S] << "\n";

        ii temp = en;
        vector<ii> path;
        while (temp != st)
        {
            path.push_back(temp);
            temp = par[temp.F][temp.S];
        }
        path.push_back(st);
        reverse(path.begin(), path.end());
        vector<pair<lli, lli>> xd;
        for (auto x : path)
        {

            // cout << x.F << " " << x.S << "\n";
            xd.push_back({x.F, x.S});
        }
        for (int i = 0; i < xd.size(); i++)
        {
            if ((xd[i].F == xd[i + 1].F) && (xd[i].S - 1 == xd[i + 1].S))
            {
                cout << "L";
            }
            else if ((xd[i].F + 1 == xd[i + 1].F) && (xd[i].S == xd[i + 1].S))
            {
                cout << "D";
            }
            else if ((xd[i].F + 1 == xd[i + 1].F) && (xd[i].S == xd[i + 1].S))
            {
                cout << "D";
            }
            else if ((xd[i].F == xd[i + 1].F) && (xd[i].S + 1 == xd[i + 1].S))
            {
                cout << "R";
            }
            else if ((xd[i].F - 1 == xd[i + 1].F) && (xd[i].S == xd[i + 1].S))
            {
                cout << "U";
            }
        }
    }
    else 
    {
        cout << "NO\n";
    }
}
int main()
{
    solve();
}