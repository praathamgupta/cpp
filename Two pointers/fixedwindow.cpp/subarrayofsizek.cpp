#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    while (j < n)
    {
        if ((j - i + 1) < k)
        {
            sum += a[j];
            j++;
        }
        else
        {
            sum += a[j];
            cout << sum << "\n";
            sum = sum - a[i];
            i++, j++;
        }
    }
}
signed main()
{
    solve();
}