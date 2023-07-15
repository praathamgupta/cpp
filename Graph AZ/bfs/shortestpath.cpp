
/*  Find the shortest path from start to end
6 6
S.#...
......
####.#
E.##.#
..#..#
#....#
*/
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define F first
#define S second
int n, m;
vector<string> arr;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// if knight
/*int dx[] = {2,1,-1,-2,-2,-1,1,2};
int dy[] = {-1,-2,-2,-1,1,2,2,1};*/

bool inside(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || arr[x][y] == '#')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int dist[1010][1010];
ii par[1010][1010];
void bfs(ii st)
{ // starting cell =st
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 1e9; // assume
        }
    }
    dist[st.F][st.S] = 0; // assume
    queue<ii> q;
    q.push(st);
    while (!q.empty())
    {
        ii cur = q.front();
        q.pop();
        int curd = dist[cur.F][cur.S];
        for (int k = 0; k < 4; k++)
        {
            if (!inside(cur.F + dx[k], cur.S + dy[k]))
            {
                continue;
            }
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            if (dist[neigh.F][neigh.S] < curd + 1) // relaxing condition / unvisited
            {
                dist[neigh.F][neigh.S] = curd + 1;
                par[neigh.F][neigh.S] = cur;
                q.push(neigh);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    arr.resize(n);
    ii st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'A')
            {
                st = {i, j};
            }
            else if (arr[i][j] == 'B')
            {
                en = {i, j};
            }
        }
    }
    bfs(st);
    // cout << dist[en.F][en.S];    to calculate the min distance between the starting and ending point
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << dist[i][j] << "\t";
        }
        // cout << "\n";
    }

    ii temp = en;
    vector<ii> path;
    while (temp != st)
    {
        path.push_back(temp);
        temp = par[temp.F][temp.S];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    for (auto v : path)
    {
        cout << v.F << " " << v.S << "\n"; // to print all the path which is followed
    }
}