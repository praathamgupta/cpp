#include <bits/stdc++.h>
using namespace std;
vector<string> split(string &s, char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        if (item.length() > 0)
        {
            elems.push_back(item);
        }
    }
    return elems;
}
void solve()
{
    string a, b, s;
    cin >> a >> b;
    float(c) = (stof(a) / stof(b));
    s = to_string(c);
    vector<string> a1 = split(s, '.');
    cout << (a1[0]) << " " << a1[1];
   
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
}