#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
int main()
{
    lli n, q, i;
    cin >> n >> q;
    lli a[n + 1];
    lli b[n + 1];
    lli p[n + 1];
    a[0] = 0;
    p[0] = 0;
    b[0] = 0;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = (p[i - 1] + a[i]) % mod;
        b[i] = (b[i - 1] + a[i] * i) % mod;
    }
    while (q--)
    {
        lli l, r;
        cin >> l >> r;

        if (((b[r] - b[l - 1]) % mod + (1 - l) * ((p[r]) - (p[l - 1])) % mod) % mod < 0)
        {
            cout << ((b[r] - b[l - 1]) % mod + (1 - l) * ((p[r]) - (p[l - 1])) % mod) % mod + mod;
            cout << "\n";
        }
        else
        {
            cout << ((b[r] - b[l - 1]) % mod + (1 - l) * ((p[r]) - (p[l - 1])) % mod) % mod;
            cout << "\n";
        }
    }
}