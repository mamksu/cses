#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int t, x, y;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> y >> x;

        if (x > y) {
            y -= 1;

            if (x % 2 == 0) {
                x -= 1;
                x = x * x;
                x += 1;
                cout << x - y << endl;

            } else {
                x = x * x;
                cout << x - y << endl;
            }

        } else if (y > x) {
            x -= 1;

            if (y % 2 == 0) {
                y = y * y;
                cout << y-x << endl;

            }else {
                y -= 1;
                y = y * y;
                y += 1;
                cout << y + x << endl;
            }

        }else {
            if (y % 2 == 0) {
                x -= 1;
                y = y * y;
                cout << y - x << endl;

            }else if (x % 2 == 1) {
                y -= 1;
                x = x * x;
                cout << x - y << endl;
            }
        }
    }
}