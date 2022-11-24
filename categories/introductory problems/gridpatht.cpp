#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
string t = "ULRD";
bool grid[7][7];
int res = 0;
string s;

bool valid(int x, int y, int i)
{
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7 || grid[nx][ny])
        return 0;
    return 1;
}

void f(int x, int y, int cnt)
{
    if (x == 6 && y == 0)
    {
        if (cnt == 48)
            res++;
        return;
    }
    if (s[cnt] != '?')
    {
        int i = t.find(s[cnt]);
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7 || grid[nx][ny])
            return; // obicno
        if (s[cnt] == 'L' && !valid(nx, ny, 1) && valid(nx, ny, 0) && valid(nx, ny, 3) && (s[cnt + 1] == '?' || s[cnt + 1] == 'L'))
            return;
        if (s[cnt] == 'R' && !valid(nx, ny, 2) && valid(nx, ny, 0) && valid(nx, ny, 3) && (s[cnt + 1] == '?' || s[cnt + 1] == 'R'))
            return;
        if (s[cnt] == 'U' && !valid(nx, ny, 0) && valid(nx, ny, 1) && valid(nx, ny, 2) && (s[cnt + 1] == '?' || s[cnt + 1] == 'U'))
            return;
        if (s[cnt] == 'D' && !valid(nx, ny, 3) && valid(nx, ny, 1) && valid(nx, ny, 2) && (s[cnt + 1] == '?' || s[cnt + 1] == 'D'))
            return;
        grid[nx][ny] = 1;
        f(nx, ny, cnt + 1);
        grid[nx][ny] = 0;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            char c = t[i];
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= 7 || ny >= 7 || grid[nx][ny])
                continue; // obicno
            if (c == 'L' && !valid(nx, ny, 1) && valid(nx, ny, 0) && valid(nx, ny, 3) && (s[cnt + 1] == '?' || s[cnt + 1] == 'L'))
                continue;
            if (c == 'R' && !valid(nx, ny, 2) && valid(nx, ny, 0) && valid(nx, ny, 3) && (s[cnt + 1] == '?' || s[cnt + 1] == 'R'))
                continue;
            if (c == 'U' && !valid(nx, ny, 0) && valid(nx, ny, 1) && valid(nx, ny, 2) && (s[cnt + 1] == '?' || s[cnt + 1] == 'U'))
                continue;
            if (c == 'D' && !valid(nx, ny, 3) && valid(nx, ny, 1) && valid(nx, ny, 2) && (s[cnt + 1] == '?' || s[cnt + 1] == 'D'))
                continue;
            grid[nx][ny] = 1;
            f(nx, ny, cnt + 1);
            grid[nx][ny] = 0;
        }
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin >> s;
    grid[0][0] = 1;
    f(0, 0, 0);
    cout << res;
}