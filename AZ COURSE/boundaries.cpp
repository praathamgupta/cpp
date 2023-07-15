// intersection of two boundaries

#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((max(a, c)) > min(b, d))
    {
        cout << "-1\n";
    }
    else
    {
        cout << ((max(a, c))) << " " << min(b, d);
        cout << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}