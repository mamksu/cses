#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sum, n, y, x;

    cin >> n;

    x = -1;
    sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> y;

        if (y < x) {
            sum += x - y;
        }

        x = y;
    }
    cout << sum;
}