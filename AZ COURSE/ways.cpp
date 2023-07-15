#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6;
int mul(int a, int b)
{
    int ans = ((1LL * a * b)) % mod;
    return ans;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int fact[N];
    int invfact[N];
    fact[0] = 1;
    for (int i = 1; i <= N - 1; i++)
    {
        fact[i] = mul(i, fact[i - 1]);
    }

    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--)
    {
        invfact[i] = mul(i + 1, invfact[i + 1]);
    }

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int res = mul(fact[m + n], mul(invfact[m], invfact[n]));
        cout << res << endl;
    }
}