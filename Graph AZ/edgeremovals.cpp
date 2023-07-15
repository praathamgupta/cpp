#include <bits/stdc++.h>
using namespace std;
vector<int> dig(100100);

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dig[u]++;
        dig[v]++;
    }

    int y, z;
     //dig.assign(1000100, 0); // Reset visited array
    while (q--)
    {
        cin >> y;
        if (y == 1)
        {
            cin >> z;
        }
        if (y == 2)
        {
            cout << dig[z] << "\n";
        }
    }
}

int main()
{
    solve();
    return 0;
}
