#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int componentSize[100001]; // Renamed variable from 'size' to 'componentSize'

void make(int v)
{
    parent[v] = v;
    componentSize[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}

void union1(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (componentSize[a] < componentSize[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        componentSize[a] += componentSize[b];
    }
}

bool same(int x, int y)
{
    int rx = find(x);
    int ry = find(y);
    return rx == ry;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
       parent[i]=i;
    }
    
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0)
        {
            union1(y, z);
        }
        else if (x == 1)
        {
            cout << same(y, z) << "\n";
        }
    }
}

int main()
{

    solve();

    return 0;
}
