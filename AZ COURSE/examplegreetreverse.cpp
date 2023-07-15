#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string temp;
    getline(cin, temp);
    string a[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << "Hi " << a[i] << " !";
        cout<<"\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}