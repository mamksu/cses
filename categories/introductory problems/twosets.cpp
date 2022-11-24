#include<iostream>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    long long int x, sum, da, db;
    long long int n;

    cin >> n;

    vector<long long int> a;
    vector<long long int> b;

    x = n;

    sum = 0;

    da = 0;
    db = 0;

    n = n * (n + 1);
    n = n / 2;

    if (n % 2 == 1) {
        cout << "NO";

    }else {
        cout << "YES" << endl;
        n /= 2;

        for (long long int i = x; i > 0; --i) {
            if ((sum + i) < n) {
                sum += i;
                a.push_back(i);
                da += 1;

            }else if (i != 1) {
                b.push_back(i);
                db += 1;
            }
        }
        a.push_back(1);
        da += 1;
        cout << da << endl;
        for (long long int i = 0; i < da; ++i) {
            cout << a[i] << " ";
        }
        cout << endl << db << endl;
        for (long long int i = 0; i < db; ++i) {
            cout << b[i] << " ";
        }
    }
}