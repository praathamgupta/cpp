//(abcde)/(efghij) = N

#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

void solve1()
{
    int n;
    cin >> n;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do
    {
        int abcde = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
        int fghij = arr[0 + 5] * 10000 + arr[1 + 5] * 1000 + arr[2 + 5] * 100 + arr[3 + 5] * 10 + arr[4 + 5];
        if (abcde % fghij == 0)
        {
            if (abcde / fghij == n)
            {
                cout << abcde << " " << fghij;
                cout << "\n";
            }
        }
    } while (next_permutation(arr.begin(), arr.end()));
}

void solve()
{
    int n;
    cin >> n;
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