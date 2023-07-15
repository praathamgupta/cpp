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
    b[0]=a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = a[i] - a[i-1];
    }
    for(auto x: b){
        cout<<x<<" ";
    }
}
signed main()
{
    solve();
}