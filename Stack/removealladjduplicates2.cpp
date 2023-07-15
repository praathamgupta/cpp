#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string &s, int k)
{
    vector<pair<char, short>> st;
    string res;
    for (auto ch : s)
    {
        if (st.empty() || st.back().first != ch)
            st.push_back({ch, 0});
        if (++st.back().second == k)
            st.pop_back();
    }
    for (auto &p : st)
        res += string(p.second, p.first);
    return res;
}
void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    string s2;
    cout << removeDuplicates(s, k) << "\n";
}

int main()
{
    solve();
    return 0;
}
