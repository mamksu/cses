#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x, _, gp, rp, gud, prvi, drugi;
    vector<pair<int, int>> a;

    cin >> n >> x;

    for (int i = 0; i < n; ++i)
    {
        cin >> _;
        a.push_back({_, i+1});
    }
    sort(a.begin(), a.end());

    gp = 0;
    rp = n-1;
    gud = 0;

    while (gp < rp)
    {
        if (a[gp].first + a[rp].first > x) --rp;
        if (a[gp].first + a[rp].first < x) ++gp;
        if (a[gp].first + a[rp].first == x && gp != rp)
        {
            prvi = a[gp].second;
            drugi = a[rp].second;
            if (a[gp].second > a[rp].second)
            {
                prvi = a[rp].second;
                drugi = a[gp].second;
            }
            rp = -1;
            gud = 1;
            cout << prvi << " " << drugi;
        }
    }
    if (gud == 0) cout << "IMPOSSIBLE";
}