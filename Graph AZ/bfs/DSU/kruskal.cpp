#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> parent;
vector<int> componentSize;

void make(int v)
{
    parent[v] = v;
    componentSize[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    else
        return parent[v] = find(parent[v]);
}
bool same(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if (xroot == yroot)
        return 1;
    return 0;
}
void union1(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (componentSize[a] < componentSize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        componentSize[a] += componentSize[b];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    componentSize.assign(n + 1, 1);
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
    int mstcost = 0;
    int cnt = 0;
    for (auto v : edgelist)
    {
        int x = v.second.first;  // a
        int y = v.second.second; // b

        if (!same(x, y))
        {
            mstcost += v.first;
            union1(x, y);
            cnt++;
        }
    }
    if (cnt == n - 1)
    {
        cout << mstcost << "\n";
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
