// Find maximum (or minimum) sum of a subarray of size k
// fixed window size
#include <bits/stdc++.h>
using namespace std;
int firstneg(vector<int> &a, int n, int k)
{
    list<int> l;
    vector<int> v;
    int i = 0, j = 0;
    while (j < n)
    {
        if (a[j] < 0)
        {
            l.push_back(a[j]);
        }
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            if (l.size() == 0)
            {
                v.push_back(0);
            }
        }
        
    }
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
    cout << firstneg(a, n, k) << "\n";
}
int main()
{

    solve();
}