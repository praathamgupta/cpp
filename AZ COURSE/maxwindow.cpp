#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    multiset<int> mt;
    for (int i = 0; i < n; i++)
    {
        mt.insert(a[i]);
        if (i - k >= 0)
        {
            mt.erase(mt.find(a[i - k]));
        }
        if (i >= (k - 1))
        {
            cout << *mt.rbegin() << " ";
        }
    }
    cout << "\n";
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