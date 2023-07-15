#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[101][100001] = {0};

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries)
{
    int n = arr.size();
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 100000; j++)
        {
            dp[i][j] = dp[i + 1][j];
            if (j - arr[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - arr[i]]);
        }
    }
    vector<vector<int>> ans;
    for (auto i : queries)
    {
        if (dp[0][i] == 1)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i - arr[j] >= 0 && dp[j + 1][i - arr[j]])
                {
                    temp.push_back(j);
                    i -= arr[j];
                }
            }
            ans.push_back(temp);
        }
        else
            ans.push_back({-1});
    }
    return ans;
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)
        cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q)
    {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++)
    {
        auto x = ans[i];
        if (x.size() == 0)
        {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1)
        {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x)
        {
            if (y < 0 || y >= N || p >= y)
            { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i])
        {
            cout << 1 << endl;
        }
        else
            cout << 101 << endl;
    }
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}