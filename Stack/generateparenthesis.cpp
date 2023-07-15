#include <bits/stdc++.h>
using namespace std;

void generatevalidparenthesis(int left, int right, string &s, vector<string> &ans)
{
    if (left == 0 && right == 0)
    {
        ans.push_back(s);
    }
    if (left > right || left < 0 || right < 0)
    {
        return;
    }
    s.push_back('(');
    generatevalidparenthesis(left - 1, right, s, ans);
    s.pop_back();
    s.push_back(')');
    generatevalidparenthesis(left, right - 1, s, ans);
    s.pop_back();
}

void solve()
{
    string s;
    cin >> s;
    //  cout << generate(s);
}

int main()
{
    solve();
    return 0;
}
