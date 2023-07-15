#include <bits/stdc++.h>
using namespace std;
#define int long long
int freq[100100];
int atmostk(string &s, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        freq[s[i]] = 0;
    }
    int ans = 0, i = 0, j = 0, cnt = 0;
    while (j < n)
    {
        freq[s[j]]++;
        if (freq[s[j]] == 1)
        {
            cnt++;
        }
        while (i <= j and cnt > k)
        {
            if (freq[s[i]] == 1)
            {
                cnt--;
            }
            freq[s[i]]--;
            i++;
        }
        ans += (j - i + 1);
        j++;
    }
    return ans;
}
int exactlyK(string &s, int n, int k)
{

    // Count of subarrays with exactly k distinct
    // elements is equal to the difference of the
    // count of subarrays with at most K distinct
    // elements and the count of subararys with
    // at most (K - 1) distinct elements
    return (atmostk(s, n, k) - atmostk(s, n, k - 1));
}
void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    cout << exactlyK(s, n, k);
}
signed main()
{
    solve();
}