#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli n;
    cin >> n;
    vector<lli> a(n);
    vector<lli> mxl(n);
    vector<lli> mxr(n);
    vector<lli> water(n);
    lli sum = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mxl[0] = a[0];
    for (lli i = 1; i < n; i++)
    {
        mxl[i] = max(a[i], mxl[i - 1]);
    }
    mxr[n - 1] = a[n - 1];
    for (lli i = n - 2; i >= 0; i--)
    {
        mxr[i] = max(a[i], mxr[i + 1]);
    }
    for (lli i = 0; i < n; i++)
    {
        water[i] = min(mxl[i], mxr[i]) - a[i];
    }
    for (lli i = 0; i < n; i++)
    {
        sum += water[i];
    }

    cout << sum << "\n";
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