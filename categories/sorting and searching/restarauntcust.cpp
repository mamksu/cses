#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<pair<int, int>> time;
    int n, a, b, najv, tr;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        time.push_back({a, 0});
        time.push_back({b, 1});
    }

    sort(time.begin(), time.end());
    tr = 0;
    najv = 0;

    for(int i = 0; i < n*2; ++i)
    {
        if (time[i].second == 0) ++tr;
        else --tr;

        if (tr > najv) najv = tr;
    }
    cout << najv;
}