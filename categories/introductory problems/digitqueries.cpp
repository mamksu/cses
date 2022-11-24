#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
ll pwr[19] = { 1 };
 
char solve(ll x) {
    if (x < 9) return x + '1';
    
    int len = 1;
    while(9 * pwr[len - 1] * len < x) {
        x -= 9 * pwr[len - 1] * len;
        len += 1;
    }
 
    return to_string(pwr[len - 1] + x / len)[x % len];
}
 
int main() {
    for (int i = 1; i < 19; ++i)
        pwr[i] = 10 * pwr[i - 1];
 
    int t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        cout << solve(x - 1) << '\n';
    }
 
    return 0;
}