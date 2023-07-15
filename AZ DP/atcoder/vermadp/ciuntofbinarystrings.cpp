#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1001][4];
int rec(int index, int match)
{
    if (index == n)
    {
        return 1;
    }
    if(dp[index][match]!=-1){
        return dp[index][match];
    }
    if (match == 0)
    {
        return dp[index][match]=((rec(index + 1, 0)) + (rec(index + 1, 1)));
    }
    if (match == 1)
    {
        return dp[index][match]= ((rec(index + 1, 1)) + (rec(index + 1, 2)));
    }
    if (match == 2)
    {
        return dp[index][match]=((rec(index + 1, 3)) + (rec(index + 1, 0)));
    }
    else
    {
        return dp[index][match]=(rec(index + 1, 2));
    }
    return dp[index][match];
}
void solve()
{
    cin >> n;
    cout<<rec(0,0)<<"\n";
}
int main()
{
     int t; cin>>t;
      memset(dp,-1,sizeof(dp));while(t--)
    solve();
}