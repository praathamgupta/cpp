#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

lli inv_cnt = 0;
vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> final;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            final.push_back(left[i]);
            i++;
        }
        else
        {
            final.push_back(right[j]);
            j++;
            inv_cnt += left.size() - i;
        }
    }
    while (i < left.size())
    {
        final.push_back(left[i]);
        i++;
    }
    while (j < right.size())
    {
        final.push_back(right[j]);
        j++;
    }
    return final;
}
vector<int> merge_sort(vector<int> arr)
{
    int n = arr.size();
    if (n <= 1)
    {
        return arr;
    }
    int half = n / 2;
    vector<int> left, right;
    for (int i = 0; i < n; i++)
    {
        if (i < half)
        {
            left.push_back(arr[i]);
        }
        else
        {
            right.push_back(arr[i]);
        }
    }
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
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
    merge_sort(a);
    // if you want to print a=merge_sort(a);
    for (int i = 0; i < n; i++)
    {
        // cout << a[i] << " ";
    }
    cout << inv_cnt%2 << "\n";
    inv_cnt=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}