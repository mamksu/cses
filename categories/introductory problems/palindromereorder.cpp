#include <bits/stdc++.h>
 
using namespace std;
 
map <char, int> box;
 
int main() {
    string s; cin >> s;
    for(char c : s)
        box[c] += 1;
    
    int rx = 0;
    for(auto [_, i] : box)
        rx += i % 2;
    
    deque <char> res;
    
    if(rx > 1) cout << "NO SOLUTION";
    else {
        for(auto &[i, r] : box)
            if(r & 1)
                while(r--)
                    res.push_back(i);
        
        for(auto [i, j] : box)
            while(j > 0) {
                res.push_back(i);
                res.push_front(i);
                j -= 2;
            }
        
        for(char c : res)
            cout << c;
    }
    
    return 0;
}