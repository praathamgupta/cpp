#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
int cnt = 0;

void bubble_sort(int a[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < (n - 1); i++)
    {

        if (a[i + 1] < a[i])
        {
            swap(a[i], a[i + 1]);
            cnt++;
        }
    }
    if (cnt == 0)
    {
        return;
    }
    bubble_sort(a, n - 1);
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble_sort(a, n);
    for (auto x : a)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}