#include <bits/stdc++.h>

using namespace std;

int f(vector<int> &v, int n)
{
    vector<int> res;

    for (int i = 0; i < n; ++i)
    {
        auto pos = upper_bound(res.begin(), res.end(), v[i]);
        if (pos == res.end())
            res.push_back(v[i]);
        else
        {
            int idx = pos - res.begin();
            res[idx] = v[i];
        }
    }

    return res.size();
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    cout << f(a, n);
}