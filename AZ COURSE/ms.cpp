// https://www.learning.algozenith.com/problems/Deque-AZ101-332
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    multiset<lli> m;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            m.insert(x);
        }
        else if (s == "erase")
        {
            cin >> x;
            auto it = m.find(x);
            if (it != m.end())
            {
                m.erase(it);
            }
        }
        else if (s == "eraseall")
        {
            cin >> x;
            auto it = m.find(x);
            if (it != m.end())
            {
                m.erase(x);
            }
        }
        else if (s == "find")
        {
            cin >> x;
            auto it = m.find(x);
            if (it != m.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (s == "count")
        {
            cin >> x;
            cout << m.count(x);
            cout<<"\n";
        }
        else if (s == "print")
        {
            for (auto it = m.begin(); it != m.end(); it++)
                cout << *it << " ";
                cout<<"\n";
        }
        else if (s == "empty")
        {
            m.clear();
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