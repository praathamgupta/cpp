#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n";
#define mod 1000000007
#define inf 1e17

int n, q;

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
class Disjoinset
{
    vector<int> componentSize, parent;

public:
    Disjoinset(int n)
    {
        componentSize.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int findpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findpar(parent[node]);
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
};
void solve()
{
    cin >> n >> q;
    int id, x, y;
    init();
    while (q--)
    {
        cin >> id >> x >> y;
        if (id == 1)
        {
            cout << same(x, y) << nl;
        }
        else if (id == 0)
        {
            unite(x, y);
        }
    }
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
class Solution {
    vector<vector<int>>g;
    vector<int>vis;
private: 
    void dfs(int node,int comp){
        vis[node]=comp;
        for(auto v: g[node]){
            if(!vis[v]){
                dfs(v,comp);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        g.resize(n+1);
        vis.assign(n+1,0);
        for(auto it : connections){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        int num_comp=0;
        for(int i=0;i<n;i++){
            if(!vis(i)){
           num_comp++;
           dfs(i,num_comp);
            }
        }
        return (num_comp-1);
    }
};