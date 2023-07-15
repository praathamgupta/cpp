#include <iostream>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

lli mul(lli a, lli b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    else
    {
        lli ans = (a * b) % mod;
        if (ans < 0)
        {
            ans = ans + mod;
        }
        return ans;
    }
}

lli binpow(lli a, lli b)
{
    lli res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

void solve()
{
    lli n, m;
    cin >> n >> m;
    lli ans = 0;
    lli i = 1;
    while (i <= n)
    {
        lli la = n / (n / i);
        lli term = mul(binpow(n / i, m), (la - i + 1) % mod);
        ans = (ans + term) % mod;
        i = la + 1;
    }
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
