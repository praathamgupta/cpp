#include <bits/stdc++.h>
using namespace std;

bool validparenthesis(string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty() || (c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{'))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

void solve()
{
    string s;
    cin >> s;
    cout << validparenthesis(s);
}

int main()
{
    solve();
    return 0;
}
