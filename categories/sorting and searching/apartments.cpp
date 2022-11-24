#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, k, bp, ap, x, count;
    vector<int> a;
    vector<int> b;

    ap = 0;
    bp = 0;
    count = 0;

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while(ap < n && bp < m)
    {
        if (b[bp] <= a[ap] + k && b[bp] >= a[ap] - k)
        {
            ++count;
            ++ap;
            ++bp;
        }
        else 
        {
            if (a[ap] + k < b[bp]) ++ap;

            else
                if (a[ap] - k > b[bp]) ++bp;
        }
    }
    cout << count;
}