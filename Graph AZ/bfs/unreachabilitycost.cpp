#include <bits/stdc++.h>
using namespace std;
#define int long
vector<vector<int>> g;
vector<int> vis;

void dfs(int node) {
    vis[node] = 1;
    for (auto v : g[node]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);

    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    int k;
    cin >> k;

    // Perform DFS from starting node k
    dfs(k);

    // Find unreachable nodes
    vector<int> unreachable;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            unreachable.push_back(i);
        }
    }

    // Output the unreachable nodes
    if (unreachable.empty()) {
        cout << "No unreachable nodes." << endl;
    } else {
        cout << "Unreachable nodes: ";
        for (auto node : unreachable) {
            cout << node << " ";
        }
        cout << endl;
    }
}

signed main() {
    solve();
    return 0;
}
