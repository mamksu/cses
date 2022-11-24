#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
char A[8][8];
int H[8];
int D1[16];
int D2[16];
 
ll dfs(int i) {
    if(i == 8) return 1;
    ll mx = 0;
    for (int j = 0; j < 8; ++j)
        if (!H[j] && !D1[i + j] && !D2[i - j + 8] && A[i][j] == '.') {
            H[j] = D1[i+j] = D2[i - j + 8] = 1;
            mx += dfs(i + 1);
            H[j] = D1[i+j] = D2[i - j + 8] = 0;
        }
 
    return mx;
}
 
int main() {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> A[i][j];
 
    cout << dfs(0);
 
    return 0;
}