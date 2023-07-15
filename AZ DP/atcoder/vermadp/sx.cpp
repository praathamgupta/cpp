#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    int cnt1=0;
    for (int i = 0; i < n-2; i++)
    {
        cnt = cnt + abs(a[i + 2] - a[i]);
    }
    cout << cnt;
}
int main()
{
    solve();
}