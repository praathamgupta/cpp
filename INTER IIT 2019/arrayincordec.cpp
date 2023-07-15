// https://codeforces.com/problemset/problem/1288/C
/*BISMILLAH*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mem(dp, x) memset(dp, x, sizeof dp)
const int mod = 1e9 + 7;

int BigMod(int a, int p, int mod)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }

    return ans;
}
int fact[2005];
int nCr(int n, int r)
{
    int factN = fact[n];
    // cout << fact[n] << endl;
    int hor = BigMod((fact[r] * fact[n - r]) % mod, mod - 2, mod);
    return (factN * hor) % mod;
}

void solve()
{
    int n, m, i, j;
    cin >> n >> m;
    cout << nCr(n + 2 * m - 1, 2 * m) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i <= 2000; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    solve();
}