#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<int> st;
     n =a.size();
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    for(auto x: st){
       // cout<<x<<" ";
    }
    int cnt = 0;
    vector<int> v;
    for (auto it = st.begin(); it != st.end(); ++it)
    {
        v.push_back(*it);
    }
    //reverse(v.begin(), v.end());
    for(auto x: v){
        cout<<x<<" ";
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (v[i + 1] - v[i] == 1)
        {
            cnt++;
        }
    }
    cout<<cnt+1;
}