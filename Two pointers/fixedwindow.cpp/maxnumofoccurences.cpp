#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int maxLetters;
    cin >> maxLetters;
    // The number of unique characters in the substring
    // must be less than or equal to maxLetters.
    int minSize;
    cin >> minSize;
    int maxSize;
    cin >> maxSize;
    // The substring size must be between minSize and maxSize inclusive.
    int n = s.size();
    int i = 0, j = 0;
    int cnt = 0;
    map<char, int> mp;

    while (j < n)
    {

        if (((j - i + 1) >= minSize) || (((j - i + 1) <= maxSize)))
        {
            mp[s[j]]++;
            j++;
        }
        else
        {
            mp[s[j]]++;
            if (mp.size() >= minSize || mp.size() <= maxSize)
            {
                if (cnt < maxLetters)
                {
                    cnt++;
                }
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
