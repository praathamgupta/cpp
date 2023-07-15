#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(int mid,int a[]){
    if(a[mid]<a[0]){
        return 1;
    }
    else{
        return 0;
    }
}
void solve(){
    int n;
    cin>>n;
   int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int lo=0;
    int hi = (n-1);
    int ans=0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if((check(mid,a))==0){
            lo = mid+1;
        }
        else{
            ans = mid;
            hi = mid-1;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;cin>>t;while(t--)
        solve();
}