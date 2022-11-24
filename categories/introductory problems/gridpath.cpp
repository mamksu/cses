#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
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
vector<vector<int>> tempgrid;
vector<int> di = {-1, 0, 0, 1};
vector<int> dj = {0, 1, -1, 0};
const int n = 48;
int ans = 0;
string s;

int mx = -1;

inline bool check(int si, int sj, vector<vector<int>> &grid)
{
    if (si >= 0 && si < 7 && sj >= 0 && sj < 7 && grid[si][sj])
        return true;
    return false;
}

void f(int i, int j, vector<vector<int>> grid, int dep = 0)
{
    grid[i][j] = 0;

    if (i == 6 && !j)
    {
        if (dep > mx)
        {
            mx = dep;
            cout << mx << endl;
        }
    }

    if (s[dep] == '?')
    {
        for (int k = 0; k < 4; ++k)
        {
            int si = i + di[k];
            int sj = j + dj[k];

            if (check(si, sj, grid))
                f(si, sj, grid, dep + 1);
        }
    }
    else
    {
        int si = i + 1, sj = j;

        if (s[dep] == 'L')
        {
            si = i;
            sj = j - 1;
        }
        else if (s[dep] == 'R')
        {
            si = i;
            sj = j + 1;
        }
        else if (s[dep] == 'U')
        {
            si = i - 1;
            sj = j;
        }

        if (check(si, sj, grid))
            f(si, sj, grid, dep + 1);
    }

    return;
}

signed main()
{
    // cin.tie(NULL)->sync_with_stdio(false);
    // cin.exceptions(cin.failbit);
    freopen("input.txt", "r", stdin);   //-> input file
    freopen("output.txt", "w", stdout); //-> output file

    cin >> s;

    vector<int> temp(7, 1);
    tempgrid.assign(7, temp);

    f(0, 0, tempgrid);
    cout << "\nans:" << endl;
    cout << ans << endl;

    return 0;
}