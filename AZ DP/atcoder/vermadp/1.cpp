#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

bool subsetsum(vector<int>& a, int n, int sum, vector<int>& dp) {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= a[i - 1]; j--) {
            dp[j] = dp[j] || dp[j - a[i - 1]];
        }
    }
    return dp[sum];
}

vector<int> getSubset(vector<int>& arr, int n, int sum, vector<int>& dp) {
    vector<int> indices;
    if (subsetsum(arr, n, sum, dp)) {
        int j = sum;
        for (int i = n; i > 0 && j > 0; i--) {
            if (dp[j] && !dp[j - arr[i - 1]]) {
                indices.push_back(i - 1);
                j -= arr[i - 1];
            }
        }
    }
    reverse(indices.begin(), indices.end());
    return indices;
}

vector<vector<int>> subset_queries(vector<int>& arr, vector<int>& queries) {
    int n = arr.size();
    vector<vector<int>> result;
    vector<int> dp(100001, 0);
    for (int i = 0; i < queries.size(); i++) {
        int sum = queries[i];
        vector<int> indices = getSubset(arr, n, sum, dp);
        result.push_back(indices);
    }
    return result;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++) cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }

    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.empty()) {
            cout << 101 << endl;
            continue;
        }

        ll sum = 0, p = -1;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y) {
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }

        if (sum == queries[i]) {
            cout << 1 << endl;
        } else {
            cout << 101 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
