#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e17

int n, m;

int par[10010];
int rnk[10010];
void init()
{
    for (int i = 0; i <= n; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
}

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

bool same(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void unite(int x, int y)
{
    int rootx = find(x);
    int rooty = find(y);
    if (rnk[rootx] < rnk[rooty])
        swap(rootx, rooty);
    rnk[rootx] += rnk[rooty];
    par[rooty] = rootx;
}

void solve()
{
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edgelist;
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
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
        if (find(x) != find(y))  // x and y are not in the same component
        {
            cnt++;
            mstcost += v.first;
            unite(x, y);
        }
    }
    if (cnt != (n - 1))
    {
        cout << "IMPOSSIBLE\n";
    }
    else
        cout << (mstcost) << "\n";
}

int main()
{
    solve();
}