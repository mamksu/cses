#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> a;

    for (int i = 0; i < n; ++i)
    {
        int _;
        cin >> _;
        a.push_back(_);
    }

    map<ll, int> cnt;

    cnt[0] = 1;
    ll sum = 0, res = 0;
    for (int y : a)
    {
        sum += y;
        res += cnt[sum - x];
        cnt[sum] += 1;
    }

    cout << res;
}