#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int n;

int unbounded(vector<int> &length, vector<int> &price, int n, int lengths)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n][lengths] != -1)
    {
        return dp[n][lengths];
    }
    if (length[n - 1] > lengths)
    {
        return dp[n][lengths] = unbounded(length, price, n - 1, lengths);
    }
    else if (length[n - 1] <= lengths)
    {
        return dp[n][lengths] = max(price[n - 1] + unbounded(length, price, n - 1, lengths - length[n - 1]), unbounded(length, price, n - 1, lengths));
    }
}

void solve()
{
    cin >> n;
    vector<int> length(n);
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        length[i] = i + 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << unbounded(length, price, n, n);
}

int main()
{
    solve();
}
