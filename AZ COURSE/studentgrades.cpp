#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, bool> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if (mp.count(x))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
            mp[x] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     int t;cin>>t;while(t--)
    solve();
}