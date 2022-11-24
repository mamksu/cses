#include<bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
	long long int n, k, _, gp, rp, count, gud;
	vector<long long int> w;	
	
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> _;
		w.push_back(_);
	}
	
	sort(w.begin(), w.end());
	
	rp = n-1;
	gp = 0;
	gud = 0;
	count = 0;
	
	while (gp < rp)
	{
		if (w[gp] + w[rp] <= k)
		{
			++count;
			++gp;
			--rp;
			gud += 2;
		}
		if (w[gp] + w[rp] > k)
		{
			--rp;
			++count;
			++gud;
		}
	}
	count += n - gud;
	cout << count;
}
