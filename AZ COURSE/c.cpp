
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long int a, b, c, x = 0, y = 0;
    long long int count = 0;
    cin >> a >> b >> c;

    if ((c % (__gcd(a, b))) == 0)
    {
        count++;
    }

    if (count != 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}