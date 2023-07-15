#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
bool is4sumpossible(vector<int> arr, int n, int x)
{
    map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            (pos[arr[i] + arr[j]] == 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (pos[x - (arr[i] + arr[j])])
            {
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (is4sumpossible)
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

    // int t;cin>>t;while(t--)
    solve();
}