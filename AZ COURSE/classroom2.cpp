#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int x[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i];
        }
        sort(x, x + n);
        int l = 1, r = x[n - 1] - x[0];
        int ans = 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cnt = 1;
            int prev = x[0];
            for (int i = 1; i < n; ++i)
            {
                if (x[i] >= prev + mid)
                {
                    cnt++;
                    prev = x[i];
                }
            }
            if (cnt >= k)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}