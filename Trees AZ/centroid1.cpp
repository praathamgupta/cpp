#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int par[200005];
int dep[200005];
int subtreesz[200005];
vector<int> ans;
int n;

void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    subtreesz[node] = 1;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
            subtreesz[node] += subtreesz[v];
        }
    }
}

void check(int node)
{
    if (ans.size() == 2)
        return;
    int flag = 0;
    for (auto v : g[node])
    {
        // clr();
        dfs(v, node, 0);
        if (subtreesz[v] > (n / 2))
        {
            check(v);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        ans.push_back(node);
    }
}

void solve()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);
    check(1);
    sort(ans.begin(), ans.end());
    cout << ans[0];
}

int main()
{
    solve();
    return 0;
}
