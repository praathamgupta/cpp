#include<bits/stdc++.h>
using namespace std;

#define int long long int
void solve(){
    int n=0;
    cin>>n;
    vector<int> a(n+1);
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=a[i]+p[i-1];
    }
    map<int,int> mp;
    for(int i=0;i<=n;i++){
        if(mp.find(p[i]%n)!=mp.end()){
            cout<<"YES"<<"\n";
            return;
        }
        mp[p[i]%n]=i;
    }
    cout<<"NO"<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t=1; 
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}