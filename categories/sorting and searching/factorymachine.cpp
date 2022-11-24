#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> a;
ll n, t;

ll f(ll x)
{
    int i = 0;
    ll suma = 0;
    while (i < n)
    {
        if (!(x / a[i]))
            break;
        else
            suma += x / a[i];
        ++i;
    }
    return suma;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    ll nm = 0;
    cin >> n >> t;

    for (ll i = 0; i < n; ++i)
    {

        ll _;
        cin >> _;
        a.push_back(_);
        if (!i)
            nm = _;
        else if (_ < nm)
            nm = _;
    }

    sort(a.begin(), a.end());

    ll lo = 0, hi = nm * t;

    while (lo < hi)
    {
        ll mi = (lo + hi) / 2;
        if (f(mi) < t)
            lo = mi + 1;
        else
            hi = mi;
    }

    cout << lo;
}