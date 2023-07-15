#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
vector<int> a;
vector<int> b;
vector<int> c;
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int i = 0, j = 0, k = 0;
    int ans = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            ans += a.size() - i;
            c[k++] = b[j++];
        }
    }
    while (i < a.size())
    {
        c[k++] = a[i++];
    }
    while (j < b.size())
    {
        c[k++] = b[i++];
    }
    cout << ans << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}