#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    multiset<int, greater<int>> pr;
    vector<int> mo;
    int n, m, _;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> _;
        pr.insert(_);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> _;
        mo.push_back(_);
    }

    for (int i = 0; i < m; ++i)
    {
        auto it = pr.lower_bound(mo[i]);

        if (it == pr.end()) cout << -1 << endl;
        else
        {
            cout << *it << endl;
            pr.erase(it);
        }
    }
}