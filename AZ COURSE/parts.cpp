#include <bits/stdc++.h>
using namespace std;
using lli = long long;
int mod = 1e9 + 7;
int add(int a, int b)
{
    int ans = 0;
    ans = (a + b) % mod;
    if (ans < 0)
        return ans + mod;
    else
        return ans;
}
int mul(int a, int b)
{
    return (1LL * a * b) % mod;
}
int binpow(int a, int b)
{

    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a;
    }
    else if (b % 2 == 1)
    {
        return mul(a, binpow(a, b - 1));
    }
    else
    {
        return mul(binpow(a, b / 2), binpow(a, b / 2));
    }
}
int inv(int a)
{
    return binpow(a, mod - 2);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 1, p = 1;
        cin >> n;
        ans = mul(n, n - 1);
        ans = mul(ans, inv(2));
        ans = add(ans, -n);
        p = mul(n, n - 1);
        p = mul(p, n - 2);
        p = mul(p, n - 3);
        p = mul(p, inv(24));
        ans = add(add(ans, p), 1);
        cout << ans << endl;
    }
    return 0;
}