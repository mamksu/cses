#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        int xx = x;
        int yy = y;
        if(y >= x){
            ll res = 1 + (yy % 2 == 0);
            y = (y - 1) / 2;
            res += 4 * (y + 1) * y;
            if(yy % 2 == 0) res += (x - 1);
            else res -= (x - 1);
            cout << res << "\n";
        }
        else{
            int X[] = {1, 4, 5, 16, 17};
            if (x <= 5){
                ll res = X[x - 1];
                if(x % 2 == 0) res -= (y - 1);
                else res += (y - 1);
                cout << res << "\n";
            }
            else{
                ll res = 36 + (x % 2);
                x -= 5;
                x = (x - 1) / 2;
                res += 4 * (x + 1) * x;
                res += 20 * x;
                if(xx % 2 == 0) res -= (y - 1);
                else res += (y - 1);
                cout << res << "\n";
            }
        }
    }
}