#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int dp[2002][2][10][2];

int isMultiple(int m)
{
    if (m < 2)
    {
        return 0;
    }

    for (int i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

int go(string &str, int idx = 0, int tight = 1, int even_pos = -1, int m = 0)
{
    if (idx == str.length())
    {
        return isMultiple(m);
    }
    else if (dp[idx][tight][even_pos][m] != -1)
    {
        return dp[idx][tight][even_pos][m];
    }
    else if (tight == 1)
    {
        int cnt = 0;
        int upper = str[idx] - '0';

        for (int i = 0; i <= upper; i++)
        {
            if (idx % 2 == 0 && i == even_pos)
            {
                cnt += go(str, idx + 1, i == upper, even_pos, (m * 10 + i) % mod);
                cnt %= mod;
            }
            else if (idx % 2 == 1 && i != even_pos)
            {
                cnt += go(str, idx + 1, i == upper, even_pos, (m * 10 + i) % mod);
                cnt %= mod;
            }
        }
        return dp[idx][tight][even_pos][m] = cnt;
    }
    else
    {
        int cnt = 0;

        for (int i = 0; i <= 9; i++)
        {
            if (idx % 2 == 0 && i == even_pos)
            {
                cnt += go(str, idx + 1, 0, even_pos, (m * 10 + i) % mod);
                cnt %= mod;
            }
            else if (idx % 2 == 1 && i != even_pos)
            {
                cnt += go(str, idx + 1, 0, even_pos, (m * 10 + i) % mod);
                cnt %= mod;
            }
        }
        return dp[idx][tight][even_pos][m] = cnt;
    }
}

void solve()
{
    int m, d;
    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof(dp));

    int result = go(b);
    result = (result - go(a) + mod) % mod;

    cout << result << "\n";
}

signed main()
{
    solve();
    return 0;
}
