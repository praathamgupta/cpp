
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n;
    cin >> n;
    long long int count = 0;
    for (long long int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                count++;
            }
            else
            {
                count = count + 2;
            }
        }
    }
    cout << count;
    cout << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}