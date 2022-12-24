#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>
long long
FLOOR(long long n, long long div)
{
    return n >= 0 ? n / div : (n - div + 1) / div;
}
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 1005;
int vis[MAXN][MAXN], dist[MAXN][MAXN];
char grid[MAXN][MAXN];
pair<int, int> kraj;
string viktor = "";
int n, m;
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};
inline void printdist()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
}
inline void bfs(pair<int, int> &start)
{
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty())
    {
        auto [i, j] = q.front();
        vis[i][j] = 1;
        q.pop();
        for (int k = 0; k < 4; ++k)
        {
            int tempi, tempj;
            tempi = i + di[k];
            tempj = j + dj[k];
            if (tempi > -1 && tempi < n && tempj > -1 && tempj < m && !vis[tempi][tempj] && grid[tempi][tempj] != '#')
            {
                q.push({tempi, tempj});
                dist[tempi][tempj] = dist[i][j] + 1;
                vis[tempi][tempj] = 1;
            }
        }
    }
}
void dfs(pair<int, int> p)
{
    auto [i, j] = p;
    if (grid[i][j] == 'A')
        return;
    for (int k = 0; k < 4; ++k)
    {
        int tempi, tempj;
        tempi = i + di[k];
        tempj = j + dj[k];
        if (tempi > -1 && tempi < n && tempj > -1 && tempj < m && grid[tempi][tempj] != '#')
        {
            if (dist[i][j] - 1 == dist[tempi][tempj])
            {
                if (k == 0)
                    viktor.push_back('U');
                else if (k == 1)
                    viktor.push_back('R');
                else if (k == 2)
                    viktor.push_back('L');
                else
                    viktor.push_back('D');
                dfs({tempi, tempj});
                break;
            }
        }
    }
    return;
}
signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);
    pair<int, int> start;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            else if (grid[i][j] == 'B')
                kraj = {i, j};
        }
    }
    bfs(start);
    dfs(kraj);
    reverse(ALL(viktor));
    if (viktor.size())
    {
        cout << "YES\n";
        int res = dist[kraj.first][kraj.second];
        cout << res << "\n";
        for (int i = 0; i < res; ++i)
            cout << viktor[i];
    }
    else
        cout << "NO";
    return 0;
}