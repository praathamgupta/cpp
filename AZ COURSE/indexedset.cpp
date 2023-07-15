/*#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int q, x;
    cin >> q;
    ordered_set st;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;

            st.insert(x);
        }
        else if (s == "find")
        {
            cin >> x;
            if (x < s.size())
            {
                cout << *(s.find_by_order(x)) << "\n";
            }

            else
            {
                cout << "-1\n";
            }
        }
        else if (s == "findpos")
        {
            cin >> x;
            cout << s.order_of_key(x) << "\n";
        }
        else if (s == "remove")
        {
            if (st.find(x) != st.end())
            {
                st.erase(st.find(x));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}*/
#include <bits/stdc++.h>
using namespace std;

// #define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
/*
    order_of_key (k)
    find_by_order(k)
*/

void solve()
{
    int q;
    cin >> q;
    ordered_set s;

    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        if (str == "remove")
        {
            int a;
            cin >> a;
            if (s.find(a) != s.end())
                s.erase(s.find(a));
        }
        if (str == "find")
        {
            int a;
            cin >> a;
            if (a < s.size())
                cout << *(s.find_by_order(a)) << "\n";
            else
                cout << "-1\n";
        }
        if (str == "findpos")
        {
            int a;
            cin >> a;
            // if(s.find(a)!=s.end())
            cout << s.order_of_key(a) << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}