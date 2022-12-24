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
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int x, n;
    cin >> x >> n;

    set<int> v;
    v.insert(0);
    v.insert(x);
    multiset<int> dist;
    dist.insert(x);

    while (n--)
    {
        int pos;
        cin >> pos;

        auto it1 = v.upper_bound(pos);
        auto it2 = it1;
        --it2;

        dist.erase(dist.find(*it1 - *it2));
        dist.insert(pos - *it2);
        dist.insert(*it1 - pos);

        v.insert(pos);

        auto ans = dist.end();
        --ans;

        cout << *ans << " ";
    }

    return 0;
}