#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
void solve(){
    lli n ;
    cin>>n;
    vector<lli>a(n);
     vector<lli>b(n);
    for (lli i = 0; i <n; i++)
    {
       cin>>a[i];
    }
    sort(a.begin(),a.end());
     for (lli i = 0; i <n; i++)
    {
       cin>>b[i];
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    lli c=1;
    for (lli i = 0; i < n; i++)
    {
       c += (a[i]*b[i]);
    }
    cout<<c-1<<"\n";
}
int main(){
     lli t;cin>>t;while(t--)
    solve();
}