#include <bits/stdc++.h>
using namespace std;
using lli = long long int;// Maximum value for 'n'

lli n, m;
lli par[100001];
lli rnk[100001];

void init()
{
    for (lli i = 0; i < n; i++)
    {
        par[i] = i;
        rnk[i] = 0;
    }
}

lli find(lli x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

bool same(lli x, lli y)
{
    lli rootx = find(x);
    lli rooty = find(y);
    if (rootx == rooty)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void unite(lli a, lli b)
{
   	a=find(a);
	b=find(b);
     if(a!=b){
     	if(size[b]>size[a]){
     		swap(a,b);
     	}
     	parent[b]=a;
     	size[a]+=size[b];
     }
}

void solve()
{
    cin >> n >> m;
    init();
    vector<pair<lli, pair<lli, lli>>> edgelist;
    lli a, b, c;
    for (lli i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edgelist.push_back({c, {a, b}});
    }
    sort(edgelist.begin(), edgelist.end());
    lli mstcost = 0;
    lli cnt = 0;
    for (auto v : edgelist)
    {
        lli x = v.second.first;  // a
        lli y = v.second.second; // b
        if (!same(x, y))         // x and y are not in the same component
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
        cout << mstcost << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // lli _t;cin>>_t;while(_t--)

    solve();

    return 0;
}