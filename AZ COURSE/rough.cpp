#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /* long long int n, y; // to seperate number before decimal and after decimal round off to get the number before decimal
     float m,z;               // and subtract the number from original number to get the number after decimal.
     cin >> n >> m;
     y = floor(m + 0.5);
     z = m - y;
     cout << y << " " << z;*/

    // you could convert the number to a string, find the position of the decimal point in that string
    // and extract two substrings, one up to that point and the other from that point onward.
    float m;
    cin >> m;
    string s1 = to_string(m);
    cout << s1.substr(0, '.') << " " << s1.substr('.', s1.size());
    ;
}