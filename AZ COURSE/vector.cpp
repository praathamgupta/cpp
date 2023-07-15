#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b))

void solve()
{
    lli q, n;
    cin >> q;
    vector<lli> a;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> n;
            a.push_back(n);
        }
        else if (s == "print")
        {
            cin >> n;
            if (n < a.size())
            {
                cout << a[n];
                cout << "\n";
            }
            else
            {
                cout << "0";
                cout << "\n";
            }
        }
        else if (s == "remove")
        {
            if (a.size() != 0)
            {
                a.pop_back();
            }
        }
        else if (s == "clear")
        {
            a.clear();
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
    {
        solve();
    }
}