#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    lli n;
    cin >> n;
    lli a[n];
    lli cnt[21];
    memset(cnt, 0, sizeof(cnt));
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
        for (lli j = 0; j <=20; j++)
        {
            if (a[i] & (1 << j))
            {
                cnt[j]++;
            }
        }
    }
    lli ans = 0;
    for (lli i = 0; i < n; i++)
    {
        lli largepos = 0;
        for (lli j = 0; j < 20; j++)
        {
            if (cnt[j])
            {
                largepos |= (1 << j);
                cnt[j]--;
            }
        }
        ans += largepos * largepos;
    }
    cout << ans << "\n";
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