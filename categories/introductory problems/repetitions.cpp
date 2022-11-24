#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    int n, d, najveci;

    cin >> a;

    n = a.length();

    najveci = 1;
    d = 1;

    for (int i = 0; i < n-1; ++i) {
        if (a[i] == a[i+1]) {
            d += 1;

        }else {
            if (d > najveci) {
                najveci = d;
            }
            d = 1;
        }
    }
    if (d > najveci) {
        najveci = d;
    }
    cout << najveci;
}