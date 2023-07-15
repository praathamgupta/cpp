#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int n, k;
int a[1000100];
int check(int x)
{
    int lastleft = 0;
    int needed = 0;
    for (int i = 0; i < n; i++)
    {
        if (lastleft >= a[i])
        {
            lastleft -= a[i];
        }
        else
        {
            needed++;
            lastleft = x - a[i];
        }
    }
    if (needed > k)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> k;
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        lo = max(lo, a[i]);
        hi += a[i];
    }
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
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