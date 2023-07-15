#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int n = 1e6 + 1;
int dp[1000010][5];
// int N;
//  string t="0100";
int rec(int level, int matched)
{
    // pruning
    if (matched == 4)
        return 0;

    // base case
    if (level == n)
    {
        return 1;
    }

    // cache check
    if (dp[level][matched] != -1)
        return dp[level][matched];

    // transition
    int ans = 0;

    if (matched == 0)
        ans = rec(level + 1, 0) % mod + rec(level + 1, 1) % mod;
    else if (matched == 1)
        ans = rec(level + 1, 1) % mod + rec(level + 1, 2) % mod;
    else if (matched == 2)
        ans = rec(level + 1, 0) % mod + rec(level + 1, 3) % mod;
    else if (matched == 3)
        ans = rec(level + 1, 2) % mod + rec(level + 1, 4) % mod;

    return dp[level][matched] = (ans % mod);
}

signed main()
{
    // not setting dp array -1 for all test cases. It will give TLE
    memset(dp, -1, sizeof(dp));

    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        cout << rec(n - N, 0) << "\n";
    }

    return 0;
}