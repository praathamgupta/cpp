#include <bits/stdc++.h>
using namespace std;

int count_permutations = 0;

void permute(int a[], int l, int r, int k)
{
    if (l == r)
    {
        count_permutations++;
        if (count_permutations == k)
        {
            for (int i = 0; i <= r; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r, k);
            swap(a[l], a[i]);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    permute(a, 0, n - 1, k);
    return 0;
}
