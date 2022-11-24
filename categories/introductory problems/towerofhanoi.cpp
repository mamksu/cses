#include <bits/stdc++.h>
 
using namespace std;
 
void f(int i, int j, int k){
    if (k == 0) {
        cout << i << ' ' << j << '\n';
        return ;
    }
 
    int nx = 6 - i - j;
    f(i, nx, k -= 1);
    cout << i << ' ' << j << '\n';
    f(nx, j, k);
 
    return ;
}
 
int main() {
    int n; cin >> n;
    cout << ((1 << n) - 1) << '\n';
    f(1, 3, n - 1);
 
    return 0;
}