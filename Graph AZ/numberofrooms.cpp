#include <bits/stdc++.h>
using namespace std;
int n, m;
int vis[1010][1010];
char arr[1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (valid(nx, ny) && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";

    return 0;
}