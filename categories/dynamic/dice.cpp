#include <iostream>

using namespace std;

int mod = 1e9 + 7;

int dp[1000001];
int P(int i)
{
    if (i == 0)
        return 1;
    if (dp[i] != -1)
        return dp[i];

    int res = 0;
    for (int k = 1; k <= 6; ++k)
        if (k <= i)
        {
            res += P(i - k);
            res %= mod;
        }

    return dp[i] = res;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; ++i)
        dp[i] = -1;

    cout << P(n);

    return 0;
}