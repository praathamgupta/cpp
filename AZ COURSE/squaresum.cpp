#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    double aag = sum / (double)n;
    int mid1 = floor(aag);
    int mid2 = ceil(aag);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i++)
    {
        ans1 += (a[i] - mid1) * (a[i] - mid1);
    }
    for (int i = 0; i < n; i++)
    {
        ans2 += (a[i] - mid2) * (a[i] - mid2);
    }
    cout << min(ans1, ans2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--)
        solve();
}