#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    string s;
    long long int n;
    vector<string> a;

    n = 0;
 
    cin >> s;
 
    sort(s.begin(), s.end());
 
    do
    {
        a.push_back(s);
        ++n;
    } while(next_permutation(s.begin(),s.end()));

    cout << n << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << endl;
    }
}