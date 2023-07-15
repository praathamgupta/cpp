#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
bool is_cycle = 0;
vector<int> any_cycle;
void dfs(int node, int par)
{
    parent[node] = par;
    // any_cycle.push_back(node);
    col[node] = 2;
    for (auto v : g[node])
    {
        if (v == parent[node])
        {
            continue;
        }
        if (col[v] == 1)
        {
            dfs(v, node);
        }
        else if (col[v] == 2)
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
    parent.clear();
    parent.resize(n + 1);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
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