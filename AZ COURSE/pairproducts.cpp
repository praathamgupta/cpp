#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
void solve()
{
    int m, n;
    cin >> m >> n;
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != i)
            {
                mp[(abs(v[i] - v[j]))]++;
            }
        }
    }
    lli mul = 1;
    for (auto &entry : mp)
    {
        mul = (mul * entry.first) % n;
    }

    cout << mul << endl;
}
int main()
{
    // int t;cin>>t;while(t--)
    solve();
}