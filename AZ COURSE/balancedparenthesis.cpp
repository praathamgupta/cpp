#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int left, int right, string &s, vector<string> &answer)
{
    if (left == 0 && right == 0)
    {
        answer.push_back(s);
    }

    if (left > right || left < 0 || right < 0)
    {
        return;
    }

    s.push_back('(');
    generateParenthesis(left - 1, right, s, answer);
    s.pop_back();

    s.push_back(')');
    generateParenthesis(left, right - 1, s, answer);
    s.pop_back();
}

int main()
{
    int n;

    cin >> n;
    vector<string> ans;
    string s;
    generateParenthesis(n / 2, n / 2, s, ans);
    for (auto k : ans)
    {
        cout << k << "\n";
    }
    return 0;
}