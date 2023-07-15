#include <bits/stdc++.h>
using namespace std;
bool dp[1001][1001];
int minsubsetdiff(vector<int> a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++) // isliye 0 se start nai kiya
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i < (n + 1); i++)
    {
        for (int j = 1; j < (sum + 1); j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]];
            }
        }
    }
    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--)
    {
        if (dp[n][j] == 1)
        {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
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
    cout << minsubsetdiff(a, n) << "\n";
}
int main()
{
    solve();
}