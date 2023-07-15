#include <bits/stdc++.h>
using namespace std;
string string_concatenate(string p, string q)
{
    string result = p + " " + q;
    return result;
}
int main()
{
    string s, g, rev;
    cout << "Enter your name:";
    cin >> s;
    cout << "Enter your surname: ";
    cin >> g;
    cout << "Result:  " << string_concatenate(s, g) << endl;
    if (s == g)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Unequal" << endl;
    }
    // for string size
    cout << "Size: " << s.size();
    // string rev
    for (int i = s.size() - 1; i >= 0; i--)
    {
        rev.push_back(s[i]);
    }
    cout << rev << endl;
    // palindrome;
    if (s == rev)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}