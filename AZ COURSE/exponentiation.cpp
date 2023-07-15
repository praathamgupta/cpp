
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a, b, c, i, p, x;
    cin >> a >> b >> c >> p;
    long long int ans = 1;
    while (c > 0)
    {
        if (c % 2 == 1)
        {
            ans = (ans * a) % p;
        }
        a = a * a % p;
        x /= 2;
    }
    cout << ans;
    cout << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}