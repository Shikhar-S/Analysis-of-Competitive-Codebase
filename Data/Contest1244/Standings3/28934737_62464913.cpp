#include <bits/stdc++.h>
using namespace std;


int main() {
    long long t;
    cin >> t;
    while(t--)
    {
    	long long a, b, c, d, k;
    	cin >> a >> b >> c >> d >> k;
    	long long x, y;
    	if(a%c==0)
    	x = a/c;
    	else
    	x = a/c+1;
    	if(b%d==0)
    	y = b/d;
    	else
    	y = b/d+1;
    	if(x+y>k)
    	cout << -1<<endl;
    	else
    	cout << x <<" "<<k-x<<endl;
	}
}
