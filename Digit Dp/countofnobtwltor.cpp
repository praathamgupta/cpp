// count of no btw l to r
#include <bits/stdc++.h>
using namespace std;
string r;
int dp[20][200][2];

int f(string &num, int n, int x, bool tight)
{
    // base cases
    if (n == 1)
    {
        if (tight and x >= 0 and x <= (num[num.size() - n] - '0'))
            return 1;
        else if (!tight and x >= 0 and x <= 9)
            return 1;
        else
            return 0;
    }

    int &ans = dp[n][x][tight];
    if (ans != -1)
        return ans;

    ans = 0;
    int ub = tight ? (num[num.size() - n] - '0') : 9;
    for (int dig = 0; dig <= ub; dig++)
    {
        ans += f(num, n - 1, x - dig, (tight & (dig == ub)));
    }

    return ans;
}

void solve()
{
    // code goes here
    cin >> r;
    // mem(dp,-1);
    memset(dp, -1, sizeof(dp));
    cout << f(r, r.size(), 20, 1);
}
int main()
{
    solve();
}