#include <bits/stdc++.h>
using namespace std;
using lli = long long;

vector<vector<lli>> g(1001);
vector<lli> vis(1001, 0);
vector<vector<lli>> paths; // To store all the paths

void dfs(lli node, lli par, vector<lli> path)
{
    path.push_back(node); // Add the current node to the path
    vis[node] = 1;        // Mark the node as visited

    if (node == par) // If the current node is the target node (n), store the path
    {
        vis[node] = 0; // make this false because we are backtracking and
        // if they see that we have visited this then this will no take into count
        paths.push_back(path);
        return;
    }

    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, par, path); // Continue DFS from the unvisited neighboring node
        }
    }

    // vis[node] = 0; // Reset the visited status after exploring all paths from the node
}

void solve()
{
    lli n, m;
    cin >> n >> m;
    for (lli i = 0; i < m; i++)
    {
        lli a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<lli> path;
    dfs(1, n, path);

    // Print all the paths
    for (const auto &p : paths)
    {
        cout << p.size() << "\n";
        for (lli i = 0; i < p.size(); i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
