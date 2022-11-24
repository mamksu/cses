#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
	
    int n; cin >> n;
    ll mn = 0;
    ll mx = -1e9;
    ll sm = 0;
    ll u;
    while(n--) {
        cin >> u;
        sm += u;
        mx = max(mx, sm - mn);
        mn = min(mn, sm);
    }
    
    cout << mx;
    
    return 0;
}