#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int binpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

int factorial(int k)
{
    if (k == 0 || k == 1)
    {
        return 1;
    }
    else
    {
        return (k * factorial(k - 1)) % mod;
    }
}

int inverse(int z)
{
    int x = binpow(z, (mod - 2)) % mod;
    return x;
}

void solve()
{
    int n;
    cin >> n;
    // int result = (factorial(n) * inverse(factorial(n - 2)) % mod) * inverse(2) % mod;
    // cout << result << endl;
    
    for (int r = 0; r <= n; r++)
    {
      int result =(factorial(n) * inverse(factorial(n - r)) % mod) * inverse(factorial(r)) % mod;
      cout<<result<<" ";
    }
}
///nCr = fact(n)  * inverse(r!) * (inverse(n-r))!
signed main()
{
    solve();
    return 0;
}
