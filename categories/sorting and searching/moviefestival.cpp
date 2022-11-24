#include<bits/stdc++.h>

using namespace std;

bool po_drugom(pair<int, int> L, pair<int, int> R) {
        if (L.second == R.second) return L.first < R.first;
        return L.second < R.second;
    }

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b, broj, gleda, sljedeci;
    vector<pair<int, int>> time;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        time.push_back({a, b});
    }

    sort(time.begin(), time.end(), po_drugom);
    
    gleda = time[0].second;

    broj = 1;
    
    for (int i = 0; i < n-1; ++i)
    {
        if (gleda <= time[i+1].first)
        {
            gleda = time[i+1].second;
            ++broj;
        }
    }

    cout << broj;
}