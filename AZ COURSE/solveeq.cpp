#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

lli Bin_Mul(lli a, lli b, lli p)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2)
        {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b /= 2;
    }
    return ans;
}

lli func(lli a, lli b, lli p, char op)
{
    if (op == '+')
    {
        return (a + b) % p;
    }
    else if (op == '-')
    {
        return (a - b) % p;
    }
    else if (op == '*')
    {
        return (a * b) % p;
    }
    else if (op == '/')
    {
        return (a * Bin_Mul(b, p - 2, p)) % p;
    }
    else
    {
        return -1;
    }
}

void solve()
{
    char par;
    char op1, op2;
    lli a, b, c, p;
    string m;
    lli ans = 0;
    cin >> par >> a >> op1 >> b >> op2 >> c >> par >> m >> p;
    // cout<<a<<op1<<b<<op2<<c<<m<<p<<"\n";

    if (op1 != '/' && op2 != '/')
    {
        if (op1 == '*')
        {
            ans += (a * b) % p;
            ans = func(ans, c, p, op2);
        }
        else if (op2 == '*')
        {
            ans += (b * c) % p;
            ans = func(a, ans, p, op1);
        }
        else
        {
            ans += func(a, b, p, op1);
            ans = func(ans, c, p, op2);
        }
    }
    else if (op1 == '/')
    {
        ans += func(a, b, p, op1);
        ans = func(ans, c, p, op2);
    }
    else if (op2 == '/')
    {
        ans += func(b, c, p, op2);
        ans = func(a, ans, p, op1);
    }
    cout << (ans % p + p) % p << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}