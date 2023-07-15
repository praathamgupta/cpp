#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
lli dx[] = {1, 0, -1, 0};
lli dy[] = {0, -1, 0, 1};
lli vis[1001][1001];
lli n, m;
char grid[1001][1001];
bool check(lli i, lli j)
{
    if (i >= n || i < 0 || j < 0 || j >= m || grid[i][j] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void dfs(lli i, lli j)
{
    vis[i][j] = 1;
    for (lli k = 0; k < 4; k++)
    {
        lli nx = i + dx[k];
        lli ny = j + dy[k];
        if (check(nx, ny) && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}
void solve()
{

    cin >> n >> m;
    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    solve();
}