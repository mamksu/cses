#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int tree[400000];
int query(int i, int j)
{
    int mx = tree[i];
    while (i <= j)
    {
        if (i & 1)
            mx = min(mx, tree[i++]);
        if (!(j & 1))
            mx = min(mx, tree[j--]);
        i >>= 1;
        j >>= 1;
    }
    return mx;
}
int main()
{
    int n;
    cin >> n;
    ll mx = 0;
    for (int i = 0; i < n; ++i)
        cin >> tree[i + n];
    for (int i = n - 1; i; --i)
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    for (int i = 0; i < n; ++i)
    {
        int lo = 0, hi = i;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (query(mi + n, i + n) == tree[i + n])
                hi = mi;
            else
                lo = mi + 1;
        }
        ll lx = lo;
        lo = i, hi = n - 1;
        while (lo < hi)
        {
            int mi = (lo + hi + 1) / 2;
            if (query(i + n, mi + n) == tree[i + n])
                lo = mi;
            else
                hi = mi - 1;
        }
        mx = max(mx, (lo - lx + 1) * tree[i + n]);
    }
    cout << mx;
}