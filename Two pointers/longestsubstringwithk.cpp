// Find the longest substring with k unique characters in a given string
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    map<char, int> mp;
    int i = 0, j = 0;
    int mx = INT_MIN;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            mx = max(mx, (j - i + 1));
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout << mx << "\n";
}

int main()
{
    solve();
    return 0;
}
