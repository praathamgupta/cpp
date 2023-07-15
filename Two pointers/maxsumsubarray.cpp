// Find maximum (or minimum) sum of a subarray of size k
// fixed window size
#include <bits/stdc++.h>
using namespace std;
int maximum(vector<int> &a, int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MIN;
    while (j < n)
    {
        sum = sum + a[j];
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            mx = max(mx, sum);
            sum = sum - a[i];
            i++;
            j++;
        }
    }
    return mx;
}
int minimum(vector<int> &a, int n, int k)
{
    int i = 0, j = 0;
    int sum = 0;
    int mx = INT_MAX;
    while (j < n)
    {
        sum = sum + a[j];
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            mx = min(mx, sum);
            sum = sum - a[i];
            i++;
            j++;
        }
    }
    return mx;
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
    int k;
    cin >> k;
    cout << maximum(a, n, k) << " " << minimum(a, n, k);
}
int main()
{

    solve();
}