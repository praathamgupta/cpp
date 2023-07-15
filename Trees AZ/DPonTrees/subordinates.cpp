#include <bits/stdc++.h>

using namespace std;

vector<int> tree[200001];

void dfs(int node, int par, vector<int> &ans)
{
    int subords = 0;
    for (auto v : tree[node])
    {
        if (v != par)
        {
            dfs(v, node, ans);
            subords += (1 + ans[v]);
        }
    }
    ans[node] = subords;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }

    vector<int> ans(n + 1);
    dfs(1, 0, ans);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

}
