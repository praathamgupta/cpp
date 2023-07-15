#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        cout << ((n * (n - 3)) / 2) % N;
        cout << "\n";
    }

    return 0;
}