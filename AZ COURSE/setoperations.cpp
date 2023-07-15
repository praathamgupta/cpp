#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n + m);
    vector<int> d(n + m);
    vector<int> e(n + m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto it1 = set_union(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    // it-c.begin()  to count the elements of union;
    auto it2 = set_intersection(a.begin(), a.end(), b.begin(), b.end(), d.begin());
    auto it3 = set_difference(a.begin(), a.end(), b.begin(), b.end(), e.begin());
    for (auto st1 = c.begin(); st1 != it1; st1++)
    {
        cout << *st1 << " ";
    }
    cout << "\n";
    for (auto st2 = d.begin(); st2 != it2; st2++)
    {
        cout << *st2 << " ";
    }
    cout << "\n";
    for (auto st3 = e.begin(); st3 != it3; st3++)
    {
        cout << *st3 << " ";
    }
    cout << "\n";
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