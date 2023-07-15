#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, temp;
        cin >> a >> b;
        temp = a;
        a = b;
        b = temp;
        cout << a << " " << b << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}