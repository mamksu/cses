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
const int MAXN = 1e5 + 15;
int parent[MAXN];

void ma(int v)
{
    parent[v] = v;
}

int f(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = f(parent[v]);
}

void u(int a, int b)
{
    a = f(a);
    b = f(b);
    if (a != b)
        parent[b] = a;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; ++i)
        ma(i);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        u(a, b);
    }

    vector<pair<int, int>> res;
    for (int i = 2; i <= n; ++i)
    {
        if (f(1) != f(i))
        {
            u(1, i);
            res.emplace_back(1, i);
        }
    }

    cout << res.size() << "\n";
    for (auto [u, v] : res)
        cout << u << " " << v << "\n";

    return 0;
}