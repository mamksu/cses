#include<iostream>
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    long long int n;
    long long int x;

    cin >> n;

    x = 1;

    for (int i = 0; i < n; ++i) {
        x *= 2;
        x %= mod;
    }

    cout << x;
}