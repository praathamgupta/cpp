
#include <bits/stdc++.h>
using namespace std;
bool checkprime(long long int n)
{
    for (long long int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        checkprime(n);
        if (checkprime(n) == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}