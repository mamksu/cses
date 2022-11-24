#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 1e9 + 7, MAXN = 1000;

ll dp[MAXN][MAXN];

int add(ll x, ll y)
{
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    char grid[n][n];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    bool gv = true;
    bool gh = true;

    for (int i = 0; i < n; ++i)
    {
        if (gh && grid[0][i] == '*')
            gh = false;
        if (gh)
            dp[0][i] = 1;
        if (gv && grid[i][0] == '*')
            gv = false;
        if (gv)
            dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            if (grid[i][j] != '*')
                dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);

    --n;
    cout << dp[n][n];
}