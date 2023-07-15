#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int i = 0, j = 0;
    int cnt = 0;
    int maxi=INT_MIN;
    while (j < n)
    {
        if ((j - i + 1) < k)
        {
            if (isVowel(s[j]))
            {
                cnt++;
            }
            j++;
        }
        else
        {
            if (isVowel(s[j]))
            {
                cnt++;
            }
            maxi = max(maxi,cnt);
            if (isVowel(s[i]))
            {
                cnt--;
            }
            i++;
            j++;
        }
    }

    cout << maxi << "\n";
}

int main()
{
    solve();
    return 0;
}
