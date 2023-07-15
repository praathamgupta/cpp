#include <bits/stdc++.h>
using namespace std;

using li = long long int;
const li mod = 1000000007;

void solve()
{
    li n, mult = 1;
    cin >> n;
    vector<li> a;

    for (li i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
        mult = (mult * a[i]) % mod;
    }
    cout << (mult % mod);
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    li t;
    cin >> t;
    while (t--)
        solve();
}