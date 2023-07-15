#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int i = 0, j = 0;
    int cnt = 0;
    map<char, int> mp;

    while (j < n)
    {
        if ((j - i + 1) < k)
        {
            mp[s[j]]++;
            j++;
        }
        else
        {
            mp[s[j]]++;
            if (mp.size() == k)
            {
                cnt++;
            }
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                mp.erase(s[i]);
            }

            i++;
            j++;
        }
    }

    cout << cnt << "\n";
}

int main()
{
    solve();
    return 0;
}
