#include <bits/stdc++.h>
using namespace std;
#define int int
int dp[1001][1001];
int lcs(string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    }
    else if (s1[n - 1] != s2[m - 1])
    {
        return dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
    return dp[n][m];
}
void solve()
{
    string s1, sa, sg;
    cin >> s1;
    int n = s1.size();
    memset(dp, -1, sizeof(dp));
    vector<int> vA;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'A')
        {
            vA.push_back(i);
        }
    }
    int p = vA.size();
    // cout<<s1.substr(0,4);
    int cnt = 0;
    int cnt2 = 0;

    for (int i = 0; i < p-1; i++)
    {
        if (vA[i] + 1 == vA[i + 1])
        {
            cnt2++;
        }
    }
    if (p == 1)
    {
        cout << "1"
             << " ";
    }
    else if (cnt2 == (p - 1))
    {
        cout << cnt2 + 1 << " ";
    }
    else
    {
        sa += (s1.substr(vA[0], vA[1] + 1));
        reverse(sa.begin(), sa.end());
        cout << lcs(s1, sa, n, n) << " ";
    }
    vector<int> vG;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'G')
        {
            vG.push_back(i);
        }
    }
    int q= vG.size();
    // cout<<s1.substr(0,4);
    for (int i = 0; i < q-1; i++)
    {
        if (vG[i] + 1 == vG[i + 1])
        {
            cnt++;
        }
    }
    if (q == 1)
    {
        cout << "1"
             << " ";
    }
    else if (cnt == (q - 1))
    {
        cout << cnt + 1 << " ";
    }

    else
    {
        sg += (s1.substr(vG[0], vG[1] + 1));
        reverse(sg.begin(), sg.end());
        cout << lcs(s1, sg, n, n) << " ";
    }
    cout<<"\n";
    // cout << sa << " " << sg;
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
       {
       dp[i][j]=0;
       }
       
    }
    
}
signed main()
{

    int t;cin>>t;while(t--)
    solve();
}