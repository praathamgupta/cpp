#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
vector<int> parent;
vector<int> any_cycle;
vector<int> cntcycle;
vector<int> prefixorder;

bool is_cycle = 0;
void dfs(int node, int par)
{
    parent[node] = par;
    col[node] = 2;
    for (auto v : g[node])
    {
        if (col[v] == 1)
        {
            // mode v is a forward edge
            dfs(v, node);
        }
        else if (col[v] == 2)
        {
            // mode v is a backward edge
            // we found a circle
            if (is_cycle = 0)
            {
                int temp = node;
                while (temp != v)
                {
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin(), any_cycle.end());
            }
            cntcycle[node]++;
            cntcycle[parent[v]]--;
            is_cycle = 1;
        }
        else if (col[v] == 3)
        {
            // mode v is a cross edge
            // unimp
        }
    }
    col[node] = 3;
    prefixorder.push_back(node);
}
int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    parent.assign(n + 1, 0);
    cntcycle.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i, 0);
        }
    }
    // for node in any cycle
    for (auto v : prefixorder)
    {
        cntcycle[parent[v]] += cntcycle[v];
    }
    int cntnode = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cntcycle[i] > 0)
        {
            cntnode++;
        }
    }
    // cout << cntnode << "\n";
}
