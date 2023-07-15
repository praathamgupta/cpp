#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )
void solve()
{
    lli n, q;
    cin >> n >> q;
    vector<lli> a(n);
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    while (q--)
    {
        lli t, x;
        cin >> t >> x;
        if (t == 1)
        {
            if (lower_bound(a.begin(), a.end(), x) != a.end())
            {
                cout << *(lower_bound(a.begin(), a.end(), x)) << ' ';
            }
            else
            {
                cout << "-1 ";
            }
        }
        else if (t == 2)
        {
            if (upper_bound(a.begin(), a.end(), x) != a.end())
            {
                cout << *(upper_bound(a.begin(), a.end(), x)) << ' ';
            }
            else
            {
                cout << "-1 ";
            }
        }
        else if (t == 3)
        {
            cout << (upper_bound(a.begin(), a.end(), x) - a.begin()) << ' ';
        }
        else if (t == 4)
        {

            {
                cout << (lower_bound(a.begin(), a.end(), x)) - a.begin() << " ";
            }
        }
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli t;
    cin >> t;
    while (t--)
        solve();
}