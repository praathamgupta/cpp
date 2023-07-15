#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e17

int n;
vector<vector<char>> grid(n + 1, vector<char>(n + 1));
vector<vector<int>> vis(n + 1, vector<int>(n + 1));
vector<int> area;
vector<int> perimeter;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == '#')
        return 1;
    return 0;
}

void dfs(int x, int y, int comp)
{
    vis[x][y] = comp;
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (check(nx, ny) && !vis[nx][ny])
            dfs(nx, ny, comp);
    }
}

void area_perimeter()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j])
            {
                area[vis[i][j]]++;
            }
            for (int k = 0; k < 4; k++)
            {
                if (!check(i + dx[k], j + dy[k]))
                {
                    perimeter[vis[i][j]]++;
                }
            }
        }
    }
}

void solve()
{
    cin >> n;
    grid.assign(n + 1, vector<char>(n + 1, '.'));
    vis.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '#' && !vis[i][j])
            {
                comp++;
                dfs(i, j, comp);
            }
        }
    }
    area.assign(comp + 2, 0);
    perimeter.assign(comp + 2, 0);
    area_perimeter();
    int mx = -1e9;
    for (auto i : area)
    {
        mx = max(i, mx);
    }
    vector<int> ans;
    for (int i = 1; i <= comp; i++)
    {
        if (area[i] == mx)
            ans.push_back(i);
    }
    //     The loop for (auto i : area) iterates over each element i in the area vector, which contains the area of each connected component.
    //     The variable mx is updated to store the maximum value among all the elements in area.

    //     After finding the maximum area (mx), a vector ans is initialized to store the indices of the connected components that have the maximum area.
    if (ans.size() == 1)
    {
        cout << area[ans[0]] << " " << perimeter[ans[0]] << nl;
    }
    //     The loop for (int i = 1; i <= comp; i++) iterates from 1 to comp,
    // which represents the total number of connected components. For each index i,
    // if the area of the connected component with index i is equal to the maximum area mx, then it is added to the ans vector.

    // If the size of the ans vector is 1, it means there is only one connected component with the maximum area.
    // In this case, the area and perimeter of that component are printed.
    else
    {
        int mn = 1e9;
        for (int i = 0; i < ans.size(); i++)
        {
            mn = min(perimeter[ans[i]], mn);
        }
        cout << mx << " " << mn << nl;
    }
    //     If the size of the ans vector is greater than 1, it means there are multiple connected components with the maximum area.
    // In this case, a variable mn is initialized to a very large value (1e9) to find the minimum perimeter among these components.
    // The loop for (int i = 0; i < ans.size(); i++) iterates over the indices in the ans vector and updates mn to store the minimum perimeter
    // among the connected components with maximum area.

    // Finally, the maximum area (mx) and minimum perimeter (mn) are printed.
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << fixed << setprecision(0);
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}