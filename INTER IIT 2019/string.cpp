// Given a string containing alternating char and single digit int, print a string after following these rules:

//         Eg.If the string is a3f5g7b2, print aaa119bb119fffff119ggggggg
// 3 5 7 2 = v[i]      afgb= s[i]
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v;
    for (int i = 1; i < n; i += 2)
    {
        v.push_back((s[i] - '0'));
    }
    int x = v.size();
    // sort(v.begin(), v.end());
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < x; i++)
    {
        sum = sum + v[i];
        maxi = max(maxi, v[i]);
    }
    // cout<<sum;
    int p = maxi;

    int lcm1 = (p * sum) / (__gcd(p, sum));
    // cout << lcm1;
    string s1;
    for (int i = 0; i < n; i += 2)
    {
        s1.push_back((s[i]));
    }
    // cout << s1;
    string result;
    for (int i = 0; i < v.size(); i++)
    {
        result += string(v[i], s1[i]);
    }
    sort(result.begin(), result.end());
    string final;
    for (int i = 0; i < result.size(); i++)
    {
        
         final += result[i];
        if (i == result.length() - 1 || result[i] != result[i + 1])
        {
            final += to_string(lcm1);
        }
    }
    cout << final;
    // cout << result << endl;
}
int main()
{
    solve();
}