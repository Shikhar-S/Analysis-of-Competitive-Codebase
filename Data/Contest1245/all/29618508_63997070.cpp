#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin >> a >> b;
		int x = __gcd(a,b);
		if(x == 1)
			cout << "Finite" << '\n';
		else
			cout << "Infinite"<< '\n';
	}
	
	
	
	
	return 0;
}
