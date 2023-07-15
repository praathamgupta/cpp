// https://www.learning.algozenith.com/problems/IO-Problem-AZ101-319
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
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int x;
        cin >> x;
        string s;
        cin >> s;
        vector<string> a = split(s, '.');
        cout << ((x + stoi(a[1]))) << "." << (x + stoi(a[0]));
        cout << "\n";
    }
}