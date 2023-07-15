#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a, b;
#define F first
#define S second
int dx[] = {1, 2, 2, 1 - 1, -2, -2, -1};
int dy[] = {2, 1 - 1, -2, -2, -1, 1, 2};
bool check(int i, int j)
{
    if (i >= 1 && i <= n && j >= 1 && j <= m)
    {
        return 1;
    }
    return 0;
}
using state = pair<int, int>;
int dis[1010][1010];
int bfs(int stx, int sty)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < (m + 1); j++)
        {
            dis[i][j] = 1e9;
        }
    }
    queue<state> q;
    q.push({stx, sty});
    dis[stx][sty] = 0;
    while (!q.empty())
    {
        state cur = q.front();
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int nx = cur.F + dx[k];
            int ny = cur.S + dy[k];
            if (check(nx, ny) && dis[nx][ny] > dis[cur.F][cur.S] + 1)
            {
                dis[nx][ny] = dis[cur.F][cur.S] + 1;
                q.push({nx, ny});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y >> a >> b;
    bfs(x,y);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
}