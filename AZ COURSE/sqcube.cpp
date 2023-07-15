#include <bits/stdc++.h>
using namespace std;
void square(long long int n)
{
    long long int sq;
    for (long long int i = 1; i <= n; i++)
    {
        sq = i * i;
        if (sq == n)
        {
            cout << "YES\n";
            return;
        }
        else if (sq > n)
        {
            cout << "NO\n";
            return;
        }
    }
}

void cubed(long long int n)
{
    long long int cube;
    for (long long int i = 1; i <= n; i++)
    {
        cube = i * i * i;
        if (cube == n)
        {
            cout << "YES\n";
            return;
        }
        else if (cube > n)
        {
            cout << "NO\n";
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, n;
        long long int cube, squ;
        cin >> q >> n;
        if (q == 1)
        {
            square(n);
        }
        else if (q == 2)
        {
            cubed(n);
        }
    }
}