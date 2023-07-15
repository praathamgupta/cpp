// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6
// For example, if n=3
// there are 4 ways:
// 1+1+1
// 1+2
// 2+1
// 3
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
const lli mod = 1000000007;
void solve()
{
    lli n;
    cin >> n;
    vector<lli> dp(n + 1, 0);
    dp[0] = 1;
    for (lli i = 1; i < n + 1; i++)
    {
        dp[i]=0;
        for (lli x = 1; x <= 6; x++)
        {
            if (x > i)
            {
                break;
            }
            else
                dp[i] += dp[i - x] % mod;
        }
    }
    cout << dp[n] % mod << "\n";
}
int main()
{
    solve();
}