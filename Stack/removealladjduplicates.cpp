#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    stack<char> st;
    string s2;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        s2.push_back(st.top());
        st.pop();
    }
    cout<<s2<<"\n";
}
int main()
{
    solve();
}