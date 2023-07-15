#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

// Time & Space complexity:  O( log(min(a,b)) )

void solve()
{
    int n;
    int count = 0;
    int temp = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        ump[a[i]]++;
    }
    for (auto x1 : ump)
    {

        if (x1.first < x1.second)
        {
            temp += (x1.second - x1.first);
        }
        if (x1.first > x1.second)
        {
            temp += x1.second;
        }
    }

    cout << count + temp;
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