#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    stack<lli> st;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            st.push(x);
        }
        else if (s == "remove")
        {
            if (st.size() != 0)
            {
                st.pop();
            }
        }
        else if (s == "print")
        {
            if (st.size() != 0)
            {
                cout << st.top();
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