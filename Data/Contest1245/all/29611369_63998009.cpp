#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	if (__gcd(a, b) == 1) {
		cout << "Finite\n";
	} else {
		cout << "Infinite\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}