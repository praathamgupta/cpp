#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    int arr[N]; // note that N and n are different.
    for (int i = 0; i < N; i++)
        arr[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        // use the technique of Partial sum to build the value at each index.
        arr[l]++;
        arr[r + 1]--;
    }
    // finally build the prefix sum.
    for (int i = 1; i < N; i++)
        arr[i] += arr[i - 1];

    // keep the values 1 where values >=k or else 0.
    for (int i = 1; i < N; i++)
        arr[i] = (arr[i] >= k);

    // now to answer query in O(1), we will build prefix sum on this 0/1 array to get count of positions.
    int prefixSum[N];
    prefixSum[0] = 0;
    for (int i = 1; i < N; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // gives the count of 1 positions in O(1).
        int ans = prefixSum[r] - prefixSum[l - 1];
        cout << ans << "\n";
    }
}

// STL practice

#include <iostream>
#include <bits/stdc++.h>
#define int long long

#define N 1000001

using namespace std;

void solve()
{

    int n, k, q;
    int l, r;
    int L, R;
    int num = 0;
    cin >> n >> k >> q;

    vector<int> v(N, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;

        v[l]++;
        v[r + 1]--;
    }

    for (int i = 0; i < v.size(); i++)
    {

        if (i > 0)
        {
            v[i] += v[i - 1];
        }
    }

    for (int i = 0; i < v.size(); i++)
    {

        if (v[i] >= k)
        {
            v[i] = 1;
        }

        else
        {
            v[i] = 0;
        }

        if (i > 0)
        {
            v[i] += v[i - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> L >> R;
        num = 0;

        num += v[R] - v[L - 1];

        cout << num << "\n";
    }
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}