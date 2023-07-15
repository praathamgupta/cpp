#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int k;
    for (int i = 0; i < n; i++)
    {
      k = lower_bound(b.begin(),b.end(),a[i])-b.begin();
    }
   cout<<k;
    
}
signed main()
{

    solve();
}