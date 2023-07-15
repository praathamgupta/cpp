#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    lli n;
    lli x1 = 0;
    cin >> n;
    vector<lli> a;
    for (lli i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        a.push_back(x);
        x1 = __gcd(x1, x);
    }
    if (x1 >= 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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