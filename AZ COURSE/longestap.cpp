// #include <bits/stdc++.h>
// using namespace std;
// void solve()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {

//         int n, i;
//         cin >> n;
//         vector<int> a;
//         vector<int> b;
//         vector<int> c;
//         for (i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             a.push_back(x);
//         }
//         for (i = 0; i < n - 1; i++)
//         {
//             b.push_back(a[i] - a[i + 1]);
//         }
//         unordered_map<int, int> mp;
//         for (i = 0; i < n - 1; i++)
//         {
//             mp[b[i]]++;
//         }

//         for (auto x1 : mp)
//         {
//             c.push_back(x1.second);
//         }
//         cout << 1 + *max_element(c.begin(), c.end());
//         cout << "\n";
//     }
// }
// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
// }
#include <bits/stdc++.h>
using namespace std;
// void solve(int& a,int& b)
// {
//     int t = a;
//     a=b;
//     b=t;
// }
int main()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int max_c = 2;
        for (int i = 0; i < n - 1;)
        {
            int j = i + 1;
            long long d = a[j] - a[i];
            int curr = 1;
            while (j < n && (a[j + 1] - a[j]) == d)
            {
                curr++;
                j++;
                /* code */
            }
            max_c = max(curr + 1, max_c);
            i = j;
            /* code */
        }

        cout << max_c << "\n";
    }
}