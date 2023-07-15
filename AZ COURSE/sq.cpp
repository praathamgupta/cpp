#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
signed main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        set<int> s, ns;
        while (q--)
        {
            int t, x;
            cin >> t >> x;
            if (t == 1)
            {
                s.insert(x);
                ns.erase(x);
                if (!s.count(x + 1))
                {
                    ns.insert(x + 1);
                }
            }
            else
            {
                if (!s.count(x))
                {
                    cout << x << "\n";
                }
                else
                {
                    cout << *ns.lower_bound(x) << "\n";
                }
            }
        }
    }
}