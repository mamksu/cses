#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);

    vector<vector<long long int>> dist;
    long long int n, m, a, b, c, q;
    vector<long long int> r;
    long long int inf;
    
    inf = 1e12 + 1;

    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
        {
            if (i == j) r.push_back(0);
            else r.push_back(inf);
        }
        dist.push_back(r);
        r.clear();
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        if (dist[a-1][b-1] > c || dist[a-1][b-1] == inf)
        {
            dist[a-1][b-1] = c;
            dist[b-1][a-1] = c;
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;

        if (dist[a-1][b-1] == inf)
        {
            cout << -1 << endl;
        }
        else {
            cout << dist[a-1][b-1] << endl;
        }   
    }
}