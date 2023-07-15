#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int a1 = 0;
    for (char ch : a)
    {
        a1 += static_cast<int>(ch);
    }
    int a2 = 0;
    for (char ch : b)
    {
        a2 += static_cast<int>(ch);
    }
    int a3 = 0;
    for (char ch : c)
    {
        a3 += static_cast<int>(ch);
    }
    cout << a1 << " " << a2 << " " << a3;
}
signed main()
{
    solve();
}