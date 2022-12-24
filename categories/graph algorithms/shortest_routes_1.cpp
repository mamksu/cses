#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll D[200000];
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll, int>>> vex(n);
    int u, v, h;
    while (m--)
    {
        cin >> u >> v >> h;
        vex[--u].emplace_back(h, --v);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> box;
    box.emplace(0, 0);
    while (!box.empty())
    {
        auto [h, x] = box.top();
        box.pop();
        if (D[x])
            continue;
        D[x] = h;
        for (auto [hx, u] : vex[x])
            if (u && !D[u])
                box.emplace(hx + h, u);
    }
    for (int i = 0; i < n; ++i)
        cout << D[i] << ' ';
}