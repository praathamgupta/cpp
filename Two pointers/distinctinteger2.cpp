#include <bits/stdc++.h>
using namespace std;
#define int long long
// subarray of A good if the
// number of different integers in that subarray is exactly B.
// exactly k = atmost k - atmost (k-1)

int atmost(int k, vector<int> &a)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    map<int, int> mp;
    while (j < a.size())
    {
        mp[a[j]]++;
        while (mp.size() > k)
        {
            auto it = mp.find(a[i]);
            it->second--;
            if (it->second == 0)
            {
                mp.erase(it);
            }
            i++;
        }
        cnt += (j - i + 1);
    }
    return cnt;
}
int exactlyk(int k, vector<int> &a)
{
    return (atmost(k, a) - (atmost(k - 1, a)));
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << exactlyk(k, a);
}
signed main()
{
    solve();
}