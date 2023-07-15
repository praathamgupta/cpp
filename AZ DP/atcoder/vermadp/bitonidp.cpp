#include <bits/stdc++.h>
using namespace std;
int longestbitonicsubseq(vector<int> &a, int n)
{

    n = a.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
      vector<int> dp2(n, 1);
    int maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[i] > a[j] && dp2[i] < dp2[j] + 1)
            {
                dp2[i] = dp2[j] + 1;
            }
        }
        maxi = max(maxi, dp[i] + dp2[i] - 1);
    }
    return maxi;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestbitonicsubseq(a, n);
}

int main()
{
    solve();
    return 0;
}
