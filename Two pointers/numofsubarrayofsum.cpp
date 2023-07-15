// Number of Subarray with sum at most K
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = 0;
    int sum = 0;
    int ans = 0;
    while (j < n)
    {
        sum += a[j];
        while (i <= j && sum > k)
        {
            sum -= a[i];
            i++;
        }
        ans += (j - i + 1);
        j++;
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}