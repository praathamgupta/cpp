#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
ll arr[100010];
int check(ll x)
{

    ll needed = 0;
    for (int i = 1; i < n; i++)
    {
        needed += ((arr[i] - arr[i - 1]) - 1) / x;
    }
    if (needed <= k)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll lo = 0;
    ll hi = 0;
    for (int i = 1; i < n; i++)
    {
        hi = max(arr[i] - arr[i - 1], hi);
    }
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (mid > 0 && check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }

        else
            lo = mid + 1;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)

        solve();

    return 0;
}