#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    int cnt = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < (n-1); i++)
    {
        if (a[i] > a[i + 1])
        {
            cnt++;
        }
    }
    cout << cnt % 2 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}