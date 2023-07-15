#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> g[1000100];
int dep[1000100];
int par[1000100];
vector<int> child;
bool isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int node, int parent, int depth)
{
    dep[node] = depth;
    par[node] = parent;
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1);
            //child.push_back(v);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < (n - 1); i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(2, 0, 0);
    for (auto x : child)
    {
       // cout << x << " ";
    }
}
signed main()
{
    solve();
}