#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> g;
vector<int> depth;
vector<int> par;
vector<vector<int>>child;
vector<vector<int>>ancestors;
vector<int>sizeofsubtree;
void dfs(int nn,int pp,int dd,vector<int>&exploring){
      depth[nn]=dd;
      par[nn] = pp;
      exploring.push_back(nn);
      ancestors[nn]=exploring;
      sizeofsubtree[nn]=1;
      for(auto v: g[nn]){
        if(v!=pp){
            dfs(v,nn,dd+1,exploring);
            sizeofsubtree[nn]+=sizeofsubtree[v];    // basically size of subtree is 1 + size of subchild
            child[nn].push_back(v); // all the v are child
        }
      }
      exploring.pop_back();
}
int main()
{
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1);
    par.resize(n + 1);
    child.resize(n+1);
    sizeofsubtree.resize(n+1);
    for (int i = 0; i < (n - 1); i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root;
    cin>>root;
    dfs(root,0,0);
    int theight=0;
    for (int i = 1; i < (n+1); i++)
    {
       theight = max(theight,depth[i]);
    }
    cout<<theight<<"\n";
}