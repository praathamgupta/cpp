#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef pair<ll, ll> ii;
#define F first
#define S second
int n, m;
bool check(int x, int y)
{
    return (x < n && x >= 0 && y >= 0 && y < m);
}
int main()
{

    cin >> n >> m;
    int g[n][m];
    int dist[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            dist[i][j] = 1e9;
        }
    }
    dist[0][0] = 0;
    deque<ii> dq;
    dq.push_front(make_pair(0, 0));
    while (!dq.empty())
    {
        ii cur = dq.front();
        dq.pop_front();
        int x = cur.F, y = cur.S;
        if (g[x][y] == 1)
        {
            int neigh_x = x;
            int neigh_y = y + 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y])
                {
                    dist[neigh_x][neigh_y] = dist[x][y];
                    dq.push_front({neigh_x, neigh_y});
                }
            }
            neigh_x = x - 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x + 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y - 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
        }

        else if (g[x][y] == 2)
        {
            int neigh_x = x;
            int neigh_y = y - 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y])
                {
                    dist[neigh_x][neigh_y] = dist[x][y];
                    dq.push_front({neigh_x, neigh_y});
                }
            }
            neigh_x = x + 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y + 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x - 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
        }

        else if (g[x][y] == 3)
        {
            int neigh_x = x + 1;
            int neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y])
                {
                    dist[neigh_x][neigh_y] = dist[x][y];
                    dq.push_front({neigh_x, neigh_y});
                }
            }
            neigh_x = x - 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y + 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y - 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
        }

        else if (g[x][y] == 4)
        {
            int neigh_x = x - 1;
            int neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y])
                {
                    dist[neigh_x][neigh_y] = dist[x][y];
                    dq.push_front({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y - 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x;
            neigh_y = y + 1;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
            neigh_x = x + 1;
            neigh_y = y;
            if (check(neigh_x, neigh_y))
            {
                if (dist[neigh_x][neigh_y] > dist[x][y] + 1)
                {
                    dist[neigh_x][neigh_y] = dist[x][y] + 1;
                    dq.push_back({neigh_x, neigh_y});
                }
            }
        }
    }
    cout << dist[n - 1][m - 1];
    return 0;
}