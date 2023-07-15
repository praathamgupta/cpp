#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << a[0] << "\n";
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }
        cout << (sum % 2) << "\n";
    }
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