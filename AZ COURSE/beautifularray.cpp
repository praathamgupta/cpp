#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int start = 0;
    int anstart = -1;
    int ansend = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int maxi = a[0];
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum = sum + a[i];
        if (sum > maxi)
        {
            maxi = sum;
            anstart = start;
            ansend = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi << "\n";
    for (int i = anstart; i <= ansend; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    solve();
}