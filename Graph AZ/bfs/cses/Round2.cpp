// directed graphs

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;
vector<int> any_cycle;
vector<int> parent;
bool is_cycle = 0;
void dfs(int node, int par)
{
    parent[node] = par;
    col[node] = 2;
    for (auto v : g[node])
    {
        if (col[v] == 1)
        {
            dfs(v, node);
        }
        if (col[v] == 2)
        {
            if (is_cycle == 0)
            {
                int temp = node;
                any_cycle.push_back(v);
                while (temp != v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            is_cycle = 1;
        }
    }
    col[node]=3;
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
    parent.resize(n + 1);
    parent.assign(n + 1, 0);
    is_cycle = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i < (n + 1); i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }
    if (is_cycle == 1)
    {
        cout << any_cycle.size() << "\n";
        for (auto x : any_cycle)
        {
            cout << x << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
int main()
{
    solve();
}