#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int n, x, sum, treba;
vector<int> a;

int main() {
    cin >> n;

    sum = 0;
    treba = n;

    for (int i = 1; i < n; ++i) {
        cin >> x;

        sum += x;
        treba += i;
    }
    cout << treba - sum;
}