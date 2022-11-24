#include<iostream>

using namespace std;
using ll = long long;

int n;

int main() {
    cin >> n;

    for (long long int i = 1; i < n+1; ++i) {
        cout << ((i-1) * (i + 4) * (i*i - 3 * i + 4)) / 2 << endl;
    }
}