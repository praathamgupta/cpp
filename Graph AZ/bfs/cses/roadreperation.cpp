#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> parent;
vector<int> compsize;
int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    else
    {
        return parent[v] = find(parent[v]);
    }
}
bool same(int x, int y)
{
    int xr = find(x);
    int xy = find(y);
    if (xr == xy)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void union1(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (compsize[a] < compsize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        compsize[a] += compsize[b];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    compsize.assign(n + 1, 1);
     for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    vector<pair<int, pair<int, int>>> edgelist;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgelist.push_back({c, {a, b}});
    }
    sort(edgelist.begin(), edgelist.end());
    int mscst = 0;
    int cnt = 0;
    for (auto v : edgelist)
    {
        // cout << v.second.first << " ";
        int x = v.second.first;
        int y = v.second.second;
        if (!same(x, y))
        {
            mscst += v.first;
            union1(x, y);
            cnt++;
        }
    }
    if (cnt == n - 1)
    {
        cout << mscst << "\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
}
signed main()
{
    solve();
}