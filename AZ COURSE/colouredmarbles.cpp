#include <bits/stdc++.h>
using namespace std;
using lli = long long;
#define mod 1000000007
long long multi(long long a, long long b, long long p)
{
    return (a * b) % p;
}
long long binary_expo(long long a, long long b, long long p)
{
    if (a == 0)
    {
        return 0;
    }
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % p;
        }
        a = ((a % p) * (a % p)) % p;
        b = b / 2;
    }
    return ans;
}
long long inv(long long a, long long p)
{
    return binary_expo(a, p - 2, p);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long fact[1000000];
    fact[0] = 1;
    for (long long i = 1; i < 1000000; i++)
    {
        fact[i] = (i * (fact[i - 1] % mod)) % mod;
    }

    long long n;
    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long x = fact[n];
        long long y = inv(fact[n - i], mod);
        long long z = inv(fact[i], mod);

        cout << (multi(multi(x, y, mod), z, mod)) << endl;
    }
}