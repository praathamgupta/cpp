#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
typedef long long LL;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> any_cycle;
bool is_cycle = 0;

void dfs(int node)
{

    col[node] = 2;
    for (auto v : g[node])
    {

        if (col[v] == 1)
        {
            dfs(v);
        }
        if (col[v] == 2)
        {
            is_cycle = 1;
        }
    }
    col[node] = 3;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.clear();
    g.resize(n + 1);
    col.clear();
    col.resize(n + 1);
    col.assign(n + 1, 1);

    is_cycle = 0;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
       //  g[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i);
        }
    }
    if (is_cycle == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}