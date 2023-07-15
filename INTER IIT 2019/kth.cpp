// / if integers are from 1 to inf
// // 1234567891011121314151617181920.....
// // fin kth place
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int k;
    cin >> k;

    string s1;
    int n = 1;

    while (s1.length() < k)
    {
        s1 += to_string(n);
        n++;
    }

    cout << s1[k - 1];
}

signed main()
{
    solve();
    return 0;
}
