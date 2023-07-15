#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
lli x = 0;
void solve()
{
    lli q, i;
    cin >> q;
    if (q == 1)
    {
        cin >> i;
        if (((x >> i) & 1) == 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    else if (q == 2)
    {
        cin >> i;
        x = x | (1LL << i);
    }
    else if (q == 3)
    {
        cin >> i;
        x = x & (~(1LL << i));
    }
    else if (q == 4)
    {
        cin >> i;
        x = x ^ (1LL << i);
    }
    else if (q == 5)
    {
        if (x == (pow(2, 60) - 1))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    else if (q == 6)
    {
        if (__builtin_popcountll(x) >= 1)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    else if (q == 7)
    {
        if (__builtin_popcountll(x) == 0)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    else if (q == 8)
    {
        cout << __builtin_popcountll(x) << "\n";
    }
    else if (q == 9)
    {
        cout << x << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}