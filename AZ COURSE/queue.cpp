#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    queue<lli> gq;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            gq.push(x);
        }
        else if (s == "remove")
        {
            if (gq.size() != 0)
            {
                gq.pop();
            }
        }
        else if (s == "print")
        {
            if (gq.size() != 0)
            {
                cout << gq.front();
                cout << "\n";
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
