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
const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

ll res_sum(ll start, ll end)
{
    return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) * TWO_MOD_INV % MOD);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    ll n;
    cin >> n;

    ll res = 0;
    ll at = 1;

    while (at <= n)
    {
        ll x = n / at;
        ll y = n / x;
        res = (res + x * res_sum(at, y)) % MOD;
        at = y + 1;
    }

    cout << res;

    return 0;
}
