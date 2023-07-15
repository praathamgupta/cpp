#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;

int mod = 1e9 + 7;

const int N = 100010;
vector<int>path;
struct edge
{
    int u, v, w;
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    edge e[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i].u = a;
        e[i].v = b;
        e[i].w = -c;
    }

    ll dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 1e18;
    }
    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool negi = false;
    for (int i = 0; i < m; i++)
    {
        int u = e[i].u;
        int v = e[i].v;
        int w = e[i].w;
        if (dist[v] > dist[u] + w)
        {
            path.push_back(dist[v]);
            negi = true;
            break;
        }
    }
    if (negi)
    {
        cout << "YES\n";
        for(auto x: path){
            cout<<x<<" ";
        }
    }
    else
    {

       cout<<"NO\n";
    }
}