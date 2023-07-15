#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        float c, d;
        c = sqrt(pow(x1 - y1, 2) + pow(x2 - y2, 2));
        d = abs(x2 - x1) + abs(y2 - y1);
        cout << setprecision(7) << c;
        cout << endl;
        cout << setprecision(7) << d;
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}