#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1005;
int vis[MAXN], d[MAXN];
int main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    edges.assign(n + 1, {});
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }
    memset(vis, -1, sizeof vis);
    for (int i = 0; i <= MAXN; ++i)
        d[i] = i;
    queue<int> q;
    q.emplace(1);
    vis[1] = 0;
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int x : edges[i])
        {
            if (vis[x] == -1)
            {
                vis[x] = vis[i] + 1;
                d[x] = i;
                q.emplace(x);
            }
        }
    }
    vector<int> ans;
    ans.emplace_back(n);
    if (vis[n] == -1)
        cout << "IMPOSSIBLE\n";
    else
    {
        cout << vis[n] + 1 << "\n";
        int i = d[n];
        ans.emplace_back(i);
        while (i != 1)
        {
            i = d[i];
            ans.emplace_back(i);
        }
        for (int k = (int)ans.size() - 1; k > -1; --k)
            cout << ans[k] << " ";
    }
}