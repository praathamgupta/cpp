#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int par[200005];
int dep[200005];
int subtreesz[200005];

void clr()
{
    memset(par, -1, sizeof(par));
    memset(dep, -1, sizeof(dep));
    memset(subtreesz, 0, sizeof(subtreesz));
}

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

void solve()
{
    int n;
    cin >> n;
    clr();

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, 0);

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (subtreesz[i] * (n - subtreesz[i]));
    }

    cout << sum << endl;
}

int main()
{
    solve();
    return 0;
}
