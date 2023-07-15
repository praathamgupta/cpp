#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
void bubble_sort(int a[], int n, int *no_swap)
{
    if (n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
            no_swap[0]++;
        }
    }
    bubble_sort(a, n - 1, no_swap);
}
void solve()
{
    int n;
    int *no_swap = new int[1];
    no_swap[0] = 0;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bubble_sort(a, n, no_swap);
    cout << (no_swap[0] % 2);
    cout << "\n";
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