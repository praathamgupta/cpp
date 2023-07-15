#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int sum = 0, temp = 0;
        for (int pos = 0; pos < n; pos++)
        {
            if ((mask >> pos) & 1)
            {
                temp += a[pos];
            }
        }
        sum += temp;
        result.push_back(sum);
    }
    bool found = false;
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] % n == 0)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
