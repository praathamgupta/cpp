// https://www.learning.algozenith.com/problems/Set-AZ101-334
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    map<string, lli> mp;
    lli y = 0;
    while (q--)
    {
        string s, x;

        cin >> s;
        cin >> x;
        if (s == "add")
        {

            cin >> y;
            mp[x] = y;
        }
        else if (s == "erase")
        {

            if (mp.count(x))
            {
                mp.erase(x);
            }
        }
        else if (s == "print")
        {
            if (mp.count(x))
            {
                cout << mp[x] << "\n";
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

    lli t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}