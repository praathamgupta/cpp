#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            cnt++;
        }
        if (a[i] == 0)
        {
            cnt2++;
        }
    }
    if (cnt == n)
    {
        cout << "0\n";
    }
    if (cnt2 == n)
    {
        cout << n << "\n";
    }
}
signed main()
{

    solve();
}