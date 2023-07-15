#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    lli n;
    cin >> n;
    lli temp;
    lli count = 0;
    vector<lli> a;
    for (lli i = 0; i < n; i++)
    {
        lli x;
        cin >> x;
        a.push_back(x);
    }
    for (lli i = 0; i < n; i++)
    {
        if (a[i] == a[i + 1])
        {
            count++;
        }
    }
    sort(a.begin(), a.end());

    if (count == (n - 1))
    {
        cout << "-1\n";
    }
    else
    {
        auto ip = unique(a.begin(), a.end());
        a.erase(ip, a.end());
        cout << a[1];
        cout << "\n";
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
        solve();
}