#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    int q;
    cin >> q;
    multimap<string, int> mp;
    while (q--)
    {
        string s, x;
        int y;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            cin >> y;
            mp.insert({x, y});
        }
        else if (s == "erase")
        {
            cin >> x;
            if (mp.find(x) != mp.end())
            {
                mp.erase(mp.find(x));
            }
        }
        else if (s == "eraseall")
        {
            cin >> x;
            if (mp.find(x) != mp.end())
            {
                mp.erase(x);
            }
        }
        else if (s == "print")
        {
            cin >> x;
            auto it = mp.find(x);
            if (it != mp.end())
            {
                cout << it->second << "\n";
            }
            else
            {
                cout << "0\n";
            }
        }
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
