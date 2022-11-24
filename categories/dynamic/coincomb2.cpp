#include <bits/stdc++.h>

using namespace std;
const int MAXX = 1e6 + 1, MOD = 1e9 + 7;
int n, x, a[101];
int dp[MAXX];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> x;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    dp[x] = 1;

    for (int j = 0; j < n; ++j)
    {
        for (int i = x; i >= 0; --i)
        {
            if (i - a[j] >= 0)
            {
                dp[i - a[j]] += dp[i];
                dp[i - a[j]] %= MOD;
            }
        }
    }

    cout << dp[0];
}