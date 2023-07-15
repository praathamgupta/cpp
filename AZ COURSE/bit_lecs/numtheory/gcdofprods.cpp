#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
lli gcd(lli a, lli b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    lli n;
    cin >> n;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli ans1 = 1;
    for (lli i = 0; i < n; i++)
    {
        ans1 = (ans1 * a[i]) % mod;
    }
}
int main()
{
    lli t;
    cin >> t;
    while (t--)
        solve();
}