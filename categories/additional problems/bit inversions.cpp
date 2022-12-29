#include <bits/stdc++.h>

using namespace std;
int mx[400000];
int l[2][400000];
int r[2][400000];
int sz[400000];

void upd(int i)
{
    sz[i] = sz[i << 1] + sz[i << 1 | 1];
    mx[i] = max({mx[i << 1], mx[i << 1 | 1], r[0][i << 1] + l[0][i << 1 | 1], r[1][i << 1] + l[1][i << 1 | 1]});

    l[0][i] = l[0][i << 1] + (l[0][i << 1] == sz[i << 1] ? l[0][i << 1 | 1] : 0);
    l[1][i] = l[1][i << 1] + (l[1][i << 1] == sz[i << 1] ? l[1][i << 1 | 1] : 0);

    r[0][i] = r[0][i << 1 | 1] + (r[0][i << 1 | 1] == sz[i << 1 | 1] ? r[0][i << 1] : 0);
    r[1][i] = r[1][i << 1 | 1] + (r[1][i << 1 | 1] == sz[i << 1 | 1] ? r[1][i << 1] : 0);

    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    int N = (2 << __lg(n)) - n;

    for (int i = 0; i < n; ++i)
    {
        l[s[i] == '1'][n + (i + N) % n] = r[s[i] == '1'][n + (i + N) % n] = 1;

        mx[n + i] = sz[n + i] = 1;
    }

    for (int i = n - 1; i > 0; --i)
        upd(i);

    int u;
    int q;
    cin >> q;
    while (q--)
    {
        cin >> u;
        u = (u - 1 + N) % n + n;

        swap(l[0][u], l[1][u]);
        swap(r[0][u], r[1][u]);

        while (u >>= 1)
            upd(u);

        cout << mx[1] << ' ';
    }
}