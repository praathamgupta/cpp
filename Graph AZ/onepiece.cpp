#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;
#define F first
#define S second
const lli mod = 1000000007;
const lli INF = 1e18;

lli n, m;
vector<vector<lli>> direc;
vector<vector<lli>> dist;

lli dx[] = {0, 0, 1, -1};
lli dy[] = {1, -1, 0, 0};

bool check(int x, int y)
{
    if (x >= 0 && y >= 0 && x < n && y < m)
        return 1;
    else
        return 0;
}

void bfs01(ii st)
{
    deque<ii> dq;
    dist[st.F][st.S] = 0;
    dq.push_back(st);

    while (!dq.empty())
    {
        ii cur = dq.front();
        dq.pop_front();
        for (int k = 0; k < 4; k++)
        {
            ii neigh = {cur.F + dx[k], cur.S + dy[k]};
            lli weight = ((direc[cur.F][cur.S] - 1) != k);

            if (check(neigh.F, neigh.S) && dist[neigh.F][neigh.S] > dist[cur.F][cur.S] + weight)
            {
                dist[neigh.F][neigh.S] = dist[cur.F][cur.S] + weight;

                if (weight == 1)
                {
                    dq.push_back(neigh);
                }
                else
                {
                    dq.push_front(neigh);
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    direc.assign(n, vector<lli>(m, -1));
    dist.assign(n, vector<lli>(m, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> direc[i][j];
        }
    }
    ii st = {0, 0};
    ii end = {n - 1, m - 1};
    bfs01(st);
    cout << dist[end.F][end.S] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}