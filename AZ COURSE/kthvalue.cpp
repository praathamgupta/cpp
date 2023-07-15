#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )
vector<lli> a, b;
lli k;
bool check(lli x)
{
    lli count = 0;
    for (lli i = 0; i < a.size(); i++)
    {
        count += upper_bound(b.begin(), b.end(), x - a[i]) - b.begin();
    }
    return count >= k;
}
void solve()
{
    lli n1, n2;
    cin >> n1 >> n2 >> k;
    a.resize(n1);
    b.resize(n2);
    for (lli i = 0; i < n1; i++)
    {
        cin >> a[i];
    }
    for (lli i = 0; i < n2; i++)
    {
        cin >> b[i];
    }
    if (n1 > n2)
    {
        swap(n1, n2);
        swap(a, b);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    lli lo = a[0] + b[0];
    lli hi = a.back() + b.back();
    lli ans = hi;
    while (lo <= hi)
    {
        /* code */
        lli mid = lo + (hi - lo) / 2;
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

signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}