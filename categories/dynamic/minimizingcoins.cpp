#include <bits/stdc++.h>

using namespace std;
const int MAXX = 1e6 + 1;
int n, x, a[101];
int dp[MAXX];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < MAXX; ++i)
        dp[i] = MAXX + 1;

    dp[x] = 0;

    for (int i = x; i >= 0; --i)
        for (int j = 0; j < n; ++j)
            if (i - a[j] >= 0)
                dp[i - a[j]] = min(dp[i - a[j]], dp[i] + 1);

    if (dp[0] == MAXX + 1)
        cout << -1;
    else
        cout << dp[0];
}