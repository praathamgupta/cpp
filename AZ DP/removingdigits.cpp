#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        int minsteps = 1e6 + 2;

        while (temp != 0)
        {
            int di = temp % 10;
            temp /= 10;

            if (di == 0)
                continue;

            minsteps = min(minsteps, 1 + dp[i - di]);
        }

        dp[i] = minsteps;
    }

    cout << dp[n];
}

int main()
{
    solve();
    return 0;
}
