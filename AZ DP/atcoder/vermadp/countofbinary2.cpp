#include <bits/stdc++.h>
using namespace std;

const long MOD = 1000000007;

long countStr(long N)
{

    long dp[N + 1][3];

    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 0;

    for (int i = 2; i <= N; i++)
    {

        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;

        dp[i][1] = dp[i - 1][0] % MOD;
        dp[i][2] = dp[i - 1][1] % MOD;
    }

    long ans = (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long N;
        cin >> N;

        cout << countStr(N);
    }

    return 0;
}