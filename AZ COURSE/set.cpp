// https://www.learning.algozenith.com/problems/Set-AZ101-334
#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    lli q, x;
    cin >> q;
    set<lli> st;
    while (q--)
    {
        string s;
        cin >> s;
        lli d;
        if (s == "add")
        {
            cin >> x;
            st.insert(x);
        }
        else if (s == "erase")
        {
            cin >> x;

            auto it = st.find(x);
            if(it != st.end()){
                st.erase(it);
            }
        }
        else if (s == "find")
        {
            cin >> x;
             auto it = st.find(x);
            if (it != st.end())
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (s == "empty")
        {
            if (!st.empty())
            {
                st.clear();
            }
        }

        else if (s == "print")
        {

            for (auto it = st.begin(); it !=
                                       st.end();
                 ++it)
            {
                cout << *it << ' ';
            }

            cout << "\n";
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