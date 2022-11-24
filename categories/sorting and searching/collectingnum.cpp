#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 1;
int a[MAXN];

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    int cnt = 1;

    for (int i = 0; i < n; ++i)
    {
        int _;
        cin >> _;
        a[_] = i;
    }

    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i + 1])
            ++cnt;
    }

    cout << cnt;
}