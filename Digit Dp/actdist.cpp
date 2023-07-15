// find the actual distance
//  suppose N = 9
//  1 2 4 5 6 7 8 9 //3 nai aana chahiya
//  x = 3 {1}
// ans = N-x
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[11][2][2];
int go(string str, int pos = 0, int tight = 1, int flag = 0)
{
    // agar 3 aaya to flag=1;
    if (pos == str.length())
    {
        if (flag == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (dp[pos][tight][flag] != -1)
    {
        return dp[pos][tight][flag];
    }
    else if (tight == 1)
    {
        int res = 0;
        for (int i = 0; i <= (str[pos] - '0'); i++)
        {
            int flg = flag;

            if (i == 3)
            {
                flg = 1;
            }
            if (i == (str[pos] - '0'))
            {
                res += go(str, pos + 1, 1, flg);
            }
            else
            {
                res += go(str, pos + 1, 0, flg);
            }
        }
        return dp[pos][tight][flag] = res;
    }
    else
    {
        int res = 0;
        for (int i = 0; i <= 9; i++)
        {
            int flg = flag;

            if (i == 3)
            {
                flg = 1;
            }

            res += go(str, pos + 1, 0, flg);
        }
        return dp[pos][tight][flag] = res;
    }
}
void solve()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    string str = to_string(n);
    cout << (n - go(str)) << "\n";
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}