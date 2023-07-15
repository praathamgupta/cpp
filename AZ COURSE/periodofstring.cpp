#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;
vector<int> kmp(string s)
{
    int n = s.length();
    vector<int> res(n + 1);
    int i = 0;
    int j = -1;
    res[0] = -1;
    while (i < n)
    {
        while (j != -1 && s[i] != s[j])
        {
            j = res[j];
        }
        i++;
        j++;
        res[i] = j;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();
    vector<int> res = kmp(s);
    if (n % (n - res[n]) == 0)
    {
        cout << (n - res[n]);
        cout << "\n";
    }
    else
    {
        cout << (n) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;cin>>t;while(t--)
    solve();
}