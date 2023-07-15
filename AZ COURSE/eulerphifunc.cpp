#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Euler_totient_function(ll n)
{
    ll result = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        ll c = 0;
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                c++;
                n /= i;
            }
        }
        if (c > 0)
        {
            ll power = (ll)pow(i, c - 1);
            ll sm = (ll)pow(i, c - 1) * (i - 1);
            result *= sm;
        }
    }
    if (n > 1)
    {
        result *= (n - 1);
    }
    return result;
}

// driver code
int main()
{
    ll n;
    cin >> n;
    cout << Euler_totient_function(n);
}