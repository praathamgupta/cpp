#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool isScramble(string a, string b)
{
    if (a.length() != b.length())
    {
        return 0;
    }
    int n = a.length();
    if (n == 0)
    {
        return 1;
    }
    if (a == b)
    {
        return 1;
    }
    // Check for the condition of anagram
    string copy_S1 = a, copy_S2 = b;

    sort(copy_S1.begin(), copy_S1.end());
    sort(copy_S2.begin(), copy_S2.end());

    if (copy_S1 != copy_S2)
    {
        return 0;
    }
    string key = (a + " " + b);
    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }

    bool flag = 0;

    for (int i = 1; i < n; i++)
    {

        if (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i, n - i),
                                                                     b.substr(i, n - i)))
        {
            flag = 1;
            return 1;
        }

        if (isScramble(a.substr(0, i), b.substr(n - i, i)) && isScramble(a.substr(i, n - i),
                                                                         b.substr(0, n - i)))
        {
            flag = 1;
            return 1;
        }
    }
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isScramble(s1, s2))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
int main()
{
     int t;cin>>t;while(t--)
    solve();
}