#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, a, b;

	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &a, &b);

		if (__gcd(a, b) == 1) {
			printf("Finite\n");
		}
		else {
			printf("Infinite\n");
		}
	}

	return 0;
}
