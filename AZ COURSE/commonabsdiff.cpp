#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int z;
    for (int i = 0; i < n; i++)
    {
       z = lower_bound(a.begin(),a.end(),abs(a[i]-a[i+1]))-a.begin()
    }
    
}
int main(){
    solve();
}