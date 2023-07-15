#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int l, r;
    cin >> l >> r;
    int p = l ^ r;
    int x = 1;
    while (x <= p)
    {
        x = x << 1;
    }
    cout << x - 1 << endl;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}