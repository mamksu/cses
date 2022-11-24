#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;

    cin >> n;

    if (n % 2 == 0) {
        x = n-1;
        y = n;

    }else {
        x = n;
        y = n-1;
    }

    if (n < 4 && n != 1) {
        cout << "NO SOLUTION";

    } else {
        for (int i = x; i > 0; i -= 2) {
            cout << i << " ";
        }
        for (int i = y; i > 0; i -= 2) {
            cout << i << " ";
        }
    }
}