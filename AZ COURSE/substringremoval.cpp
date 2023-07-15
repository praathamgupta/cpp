#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    int x, y;
    cin >> s >> x >> y;
    string first = "ab";
    string second = "ba";
    // This problem is solved by a greedy approach of first removing the substring,
    // which scores more points.
    // Erase all occurrences of that larger substring till it isn’t present in the
    // current state of the string anymore.
    // Then remove all occurrences of the smaller substring from the string.
    // Remember, after every removal, the string size reduces.
    if (y > x)
    {
        swap(x, y);
        swap(first, second);
    }
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if ((!st.empty()) && (st.top() == first[0]) && (s[i] == first[1]))
        {
            st.pop();
            ans += x;
        }
        else
        {
            st.push(s[i]);
        }
    }
    string m;
    // the remaining string after removing substring ab or ba
    while (!(st.empty()))
    {
        m += st.top();
        st.pop();
    }
    reverse(m.begin(), m.end());
    for (int i = 0; i < m.length(); i++)
    {
        if (!(st.empty()) && (st.top() == second[0]) && (m[i] == second[1]))
        {
            st.pop();
            ans += y;
        }
        else
        {
            st.push(m[i]);
        }
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}