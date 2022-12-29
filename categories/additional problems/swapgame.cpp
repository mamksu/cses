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
string s = "";

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    for (int i = 0; i < 9; ++i)
    {
        char c;
        cin >> c;
        s += c;
    }

    // horizontalni swap
    // swap(s[i], s[i+1]) ako i % 3 != 2

    // vertikalni swap
    // swap(s[i], s[i+3]) ako je i < 6

    unordered_map<string, int> d;
    queue<string> q;
    q.push(s);
    d[s] = 0;

    while (!q.empty())
    {
        string u = q.front();
        q.pop();

        if (u == "123456789")
        {
            cout << d[u];
            return 0;
        }

        for (int i = 0; i < 9; ++i)
        {
            // horizontalni
            if (i % 3 != 2)
            {
                string v = u;
                swap(v[i], v[i + 1]);
                if (!d.count(v))
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
            // vertikalni
            if (i < 6)
            {
                string v = u;
                swap(v[i], v[i + 3]);
                if (d.count(v) == 0)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    cout << d["123456789"];

    return 0;
}