#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n * 3 - 3; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            sum1 = sum1 + a[i];
        }
        for (int i = n; i < (2 * n - 1); i++)
        {
            sum2 = sum2 + a[i];
        }
        for (int i = 2 * n - 1; i < (3 * n - 3); i++)
        {
            sum3 = sum3 + a[i];
        }
        cout << sum1 - sum2 << " " << sum2 - sum3;
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