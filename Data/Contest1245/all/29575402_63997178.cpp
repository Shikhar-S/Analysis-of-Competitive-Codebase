#include <bits/stdc++.h>

using namespace std;

main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int x, y;
		cin >> x >> y;
		
		if(__gcd(x, y) == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}
}