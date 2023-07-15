#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    deque<lli> dq;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "pop")
        {
            cout << dq[0];
            cout << "\n";
            if (dq.size() != 0)
            {
                dq.pop_front();
            }
        }
        else if (s == "front")
        {
            if (dq.size() != 0)
            {
                cout << dq[0];
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