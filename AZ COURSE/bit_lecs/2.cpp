// Given an array where every element occurs an even number of times
//  except one element which occurs an odd number of times. Find the element that occurs an odd number of times.
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
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    cout << ans;
}
int main()
{
    solve();
}