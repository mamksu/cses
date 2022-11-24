#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n, x;
long long int s2, w, s;
long long int inf = 1e18;
vector<int> a;

void razdvoji(int i, long long int s1) {
    if (i >= n) {
        s2 = s - s1;
        w = abs(s2-s1);

        if (w < inf) {
            inf = w;
        }     
    }else {
        razdvoji(i + 1, s1);
        razdvoji(i + 1, s1 + a[i]);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;

        s += x;

        a.push_back(x);
    }
    razdvoji(0,0);
    cout << inf;
}