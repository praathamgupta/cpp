// One number is missing from the list of integers from 1 to n. Find that missing number.
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans ^ i;
    }
    for (int i = 0; i < n-1; i++) // find xor from a[0] to a[n-2]
    {
        ans = ans ^ a[i];
    }
    cout << ans << "\n";
}
int main()
{
    solve();
}