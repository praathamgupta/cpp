// count of subbaray with average k;
//Input: arr[ ] = {1, 4, 2, 6, 10}, N = 6, K = 4
// Output: 3
// Explanation: The subarrays with an average equal to 4 are {4}, {2, 6}, {4, 2, 6}.
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = 0;
    // sum of elements = num of elements * k
    int sum=0;
    while (j < n)
    {
        sum = sum+a[j];
        
    }
}
signed main()
{
    solve();
}