#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lli ans = 0;
    for (lli i = 29; i >= 0; i--)
    {
        vector<int> ebs;
        for (auto v : a)
        {
            if (v & (1LL << i))
            {
                ebs.push_back(v);
            }
        }
        if (ebs.size() >= x)
        {
            ans += (1LL << i);
            a = ebs;
        }
    }
    cout<<ans<<"\n";
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