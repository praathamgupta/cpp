#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

vector<int> generate(vector<int> arr)
{
    vector<int> subvals;
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((mask >> j) & 1)
            {
                sum += arr[j];
            }
        }
        subvals.push_back(sum);
    }
    sort(subvals.begin(), subvals.end());
    return subvals;
}
lli count(vector<int> arr, int x)
{
    vector<int> sub0;
    vector<int> sub1;
    lli ans = 0;
    vector<int> newarr[2];
    for (int i = 0; i < arr.size(); i++)
    {
        newarr[i & 1].push_back(arr[i]); // almost half
    }
    sub0 = generate(newarr[0]);
    sub1 = generate(newarr[1]);
    for (auto v : sub0)
    {
        ans += upper_bound(sub1.begin(), sub1.end(), x - v) - sub1.begin();
    }
    return ans;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<count(a,x)<<"\n";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}