#include <bits/stdc++.h>
using namespace std;
int check(int mid, int a[])
{
    if (a[mid] < a[0])
    {
        return 1;
    }
    else
        return 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int low = 0, high = n - 1, ans = 0, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (check(mid, a) == 0)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}