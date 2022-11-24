#include<bits/stdc++.h>

using namespace std;

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    set<int> a;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a.insert(x);
    }
    cout << a.size();
}