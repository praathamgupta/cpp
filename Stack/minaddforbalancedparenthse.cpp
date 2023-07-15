#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push('(');
        }
        else
        {
            if (st.empty())
            {
                ans++;
            }
            else
            {
                st.pop();
            }
        }
    }
    while (!st.empty())
    {
        st.pop();
        ans++;
    }
    cout << ans << "\n";
}