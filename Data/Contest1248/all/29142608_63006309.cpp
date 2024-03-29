
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <assert.h>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <random>
#include <cmath>

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;

int get(int n, int m) {
	vector<vector<int>> dp(2, vector<int>(m));
	dp[0][0] = 1;
	for (int i = 1; i < m; i++) {
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
		dp[1][i] = dp[0][i - 1] % MOD;
	}
	return (dp[0][m - 1] + dp[1][m - 1]) * 2;
}
void solve() {
	int n, m;
	cin >> n >> m;
	int ans = get(n, m) + get(m, n) - 2;
	ans %= MOD;
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout.precision(12);
	/*
	freopen("distance4.in", "r", stdin);
	freopen("distance4.out", "w", stdout);
	*/
	solve();
}