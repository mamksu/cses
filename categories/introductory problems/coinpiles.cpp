#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    long long int a, b, c, d;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> a >> b;

        c = a - b*2;
        d = b - a*2;

        if (c % -3 == 0 && c / -3 >= 0 && d % -3 == 0 && d / -3 >= 0) {
            cout << "YES" << endl;

        }else {
            cout <<  "NO" << endl;
        }
    }
}