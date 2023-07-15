#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int>a;
    for (int i = 1; i <= n; i++)
    {
       //cout<<i<<" ";
       a.push_back(i);
    }
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << (i == (n - 1) ? "\n" : " ");
        }

    } while (next_permutation(a.begin(), a.end()));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}