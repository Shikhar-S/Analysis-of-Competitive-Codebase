#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
using namespace std;
long long MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll;

vector<ll> DP1,DP2;

int main() {
	DP1.resize(1e5 + 1, 0);
	DP2.resize(1e5 + 1, 0);
	DP1[1] = 1;
	DP2[1] = 0;
	DP1[2] = 1;
	DP2[2] = 1;
	for (ll n = 3; n <= 1e5; n++) {
		DP1[n] = (DP1[n - 1] + DP2[n - 1])%MOD;
		DP2[n] = (DP1[n - 2] + DP2[n - 2])%MOD;
	}
	string S;
	cin >> S;
	ll ans = 1;
	while (S.size() > 0) {
		if (S[0] == 'm' || S[0] == 'w') {
			cout << 0 << endl;
			return 0;
		}
		ll n = 1;
		for (; n < S.size(); n++) {
			if (S[n] != S[n - 1])break;
		}
		if(n != 1 && (S[0] == 'n'||S[0] == 'u'))ans = (ans * (DP1[n] + DP2[n])) % MOD;
		S = S.substr(n);
	}
	cout << ans << endl;
}