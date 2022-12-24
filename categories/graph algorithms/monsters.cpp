#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 1003;
char grid[MAXN][MAXN];
queue<pair<int, int>> q;
const int INF = 0x3f3f3f3f;
int dist[MAXN][MAXN], n, m;

int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};

inline void bfs()
{
    while (!q.empty())
    {
        auto [index, jndex] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k)
        {
            int ni = index + di[k], nj = jndex + dj[k];

            if (ni > -1 && nj > -1 && ni < n && nj < m && dist[index][jndex] + 1 < dist[ni][nj])
            {
                dist[ni][nj] = dist[index][jndex] + 1;
                q.push({index, jndex});
            }
        }
    }
}

inline void printdist()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dist[i][j] == INF)
                cout << "-1 ";
            else
                cout << dist[i][j] << " ";
        }

        cout << "\n";
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
                q.push({i, j});
            // dist[i][j] = ((grid[i][j] == '.' || grid[i][j] == 'A') ? INF : 0);
            if (grid[i][j] != 'M')
                dist[i][j] = INF;
        }
    }

    bfs();
    printdist();

    return 0;
}