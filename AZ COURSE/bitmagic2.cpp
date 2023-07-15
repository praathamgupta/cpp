#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9 + 7;
#define endl '\n'
/*1.) __builtin_popcount(x): Counts the number of one’s(set bits) in an integer(long/long long).

Ex- int x=5;
    cout<<__builtin_popcount(x)<<endl;   //returns 2.
If x is of long type,we can use __builtin_popcountl(x) If x is of long long type,we can use __builtin_popcountll(x)

2.) __builtin_parity(x): Checks the Parity of a number.Returns true(1) if the number has odd parity(odd number of set bits) else it returns false(0) for even parity(even number of set bits).

Ex- int x=5;
    cout<<__builtin_parity(x)<<endl;   //returns 0.
If x is of long type,we can use __builtin_parityl(x) If x is of long long type,we can use __builtin_parityll(x)

3.) __builtin_clz(x): Counts the leading number of zeros of the integer(long/long long).

If x is of long type,we can use __builtin_clzl(x) If x is of long long type,we can use __builtin_clzll(x)

Ex- int x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
      cout<<__builtin_clz(x)<<endl;   //returns 27.

  Ex- long x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
      cout<<__builtin_clzl(x)<<endl;   //returns 27.

  Ex- long long x=16;       // 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00010000 (64 bits)
      cout<<__builtin_clzll(x)<<endl;   //returns 59.
4.) __builtin_ctz(x): Counts the trailing number of zeros of the integer(long/long long).

If x is of long type,we can use __builtin_ctzl(x) If x is of long long type,we can use __builtin_ctzll(x)

Ex- int x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
    cout<<__builtin_ctz(x)<<endl;   //returns 4.
In case of both __builtin_ctzl(x) and __builtin_ctzll(x),the answer is same.*/
void binary(int x)
{
    for (int i = 63; i >= 0; i--)
    {
        if (x & (1LL << i))
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
}

int msb(int x)
{
    if (x == 0)
        return -1;
    if (x < 0)
        return 63;
    return (int)__lg(x);
}

int lsb(int x)
{
    if (x == 0)
        return -1;
    return msb(x ^ (x - 1));
}

bool pow2(int &x)
{
    if (x <= 1)
        return 0;
    return (__builtin_popcountll(x) == 1);
}

int pow2_div(int x)
{
    if (x == 0)
        return -1;
    return (1LL << (__builtin_ctzll(x)));
}

int pow2_n(int x)
{
    if (x <= 1)
        return 2;
    return (1LL << (64 - (__builtin_clzll(x - 1))));
}

void solve()
{
    int x;
    cin >> x;
    binary(x);
    cout << msb(x) << endl;
    cout << lsb(x) << endl;
    cout << pow2(x) << endl;
    cout << pow2_div(x) << endl;
    cout << pow2_n(x) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t;
    cin >> _t;
    while (_t--)
        solve();
}