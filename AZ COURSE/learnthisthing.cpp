#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

//Time & Space complexity:  O( log(min(a,b)) )
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int n;cin>>n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}