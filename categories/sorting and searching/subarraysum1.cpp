#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    int l = 0, r = 0, tr = 0, cnt = 0;
    while (r < n)
    {
        if (tr + a[r] <= x)
        {
            tr += a[r];
            ++r;
            if (tr == x)
                ++cnt;
        }
        else
        {
            tr -= a[l];
            ++l;
        }
    }

    cout << cnt;
}