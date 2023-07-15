#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int getpairs(vector<int> a, vector<int> b, int n)
{
    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = a[i] - b[i];
    }
    sort(d.begin(), d.end());
    lli total = 0;
    for (int i = 0; i < n; ++i)
    {

        // If the value at that index is negative or zero
        // then we need to find the index of the
        // value just greater than -D[i]
        if (d[i] <= 0)
        {
            int k = upper_bound(d.begin(), d.end(), -d[i]) - d.begin();
            total += n - k;
        }

        // If the value at the index is positive
        // then we need to find the value of ⁿ⁻ᶦC₂
        // and break
        else
        {
            total += (n - i) * (n - i - 1) / 2;
            break;
        }
    }
    return total;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    cout << getpairs(a, b, n);
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

     int t;cin>>t;while(t--)
    solve();
}