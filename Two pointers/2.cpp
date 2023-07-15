// find max number of subarrays with 0's<=k
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli n, k;
    cin >> n >> k;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli head = -1;
    lli tail = 0;
    lli countzero = 0;
    lli ans = 0;
    while (tail < n)
    {
        while ((head + 1 < n) && ((a[head + 1] == 1 && countzero <= k) || (a[head + 1] == 0 && countzero < k)))
        {
            head++;
            if (a[head] == 0)
            {
                countzero++;
            }
        }
        ans = max(ans, head - tail + 1);
        if (head >= tail)
        {
            if (a[tail] == 0)
            {
                countzero--;
            }
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
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