/*#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

lli mul(lli a, lli b)
{
    lli ans = (a * b) % mod;
    return ans;
}
lli binpow(lli a, lli b)
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
lli inv(lli a)
{
    return binpow(a, mod - 2);
}
void solve()
{
    lli n;
    cin >> n;
    cout << (mul(mul(mul(mul(n, n - 1), n - 2), n - 3), inv(24)) % mod) % mod + mod;
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--)
        solve();
}*/
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
const lli mod = 1e9 + 7;
const lli N = 1e9 + 10;
// lli fact[];

lli multiply(lli a, lli b)
{
    lli ans = (a * b) % mod;

    return ans;
}

lli binpow(lli a, lli b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    if (b % 2 != 0)
    {
        return multiply(a, binpow(a, b - 1));
    }
    else
    {
        int temp = binpow(a, b / 2);
        return multiply(temp, temp);
    }
}

lli inverse(lli a)
{
    return binpow(a, mod - 2);
}



// void fac(){
//         fact[0] = 1;
//         for(lli i = 1 ;i<N;i++){
//             fact[i] = multiply(i,fact[i-1]);
//             fact[i]%=mod;
//     }

// }

int main()
{

    int t;
    cin >> t;
    //
    // //
    // fac();
    while (t--)
    {
        lli n;
        cin >> n;

        lli val = multiply(multiply(multiply(multiply(n, n - 1), n - 2), n - 3), inverse(24)) % mod;
        cout << ((val % mod) + mod) % mod << "\n";
    }

    return 0;
}