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
const int MAXN = 2e5 + 25;
ll v[MAXN];

struct segtree
{
    vector<ll> tree;
    segtree(ll n, ll A[]) : tree(2 * n)
    {
        for (ll i = 0; i < n; ++i)
            tree[n + i] = A[i];
        for (ll i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
    ll query(ll i, ll j)
    {
        i += tree.size() / 2;
        j += tree.size() / 2;
        ll mx = 0;
        while (i <= j)
        {
            if (i & 1)
                mx += tree[i++];
            if (!(j & 1))
                mx += tree[j--];
            i >>= 1;
            j >>= 1;
        }
        return mx;
    }
    ll operator[](ll i) { return tree[i + tree.size() / 2]; }
};

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    ll n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    segtree S(n, v);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << S.query(l, r) << "\n";
    }

    return 0;
}