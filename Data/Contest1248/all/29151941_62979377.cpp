#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <stack>
#include <deque>
#include <memory.h>
#include <string>
#include <unordered_map>

#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define vI vector<int>
#define vvI vector<vector<int>>
#define vLL vector<ll>
#define vS vector<string>
#define fori(i, n) for(int (i)=0; (i)<n; (i)++)
#define forn(it,from,to) for(int (it)=from; (it)<to; (it)++)
#define forI(tmp) for(auto(it)=(tmp).begin();(it)!=(tmp).end();(it)++)
#define PI 3.14159265356
#define LD long double
#define sc(a) scanf("%d", &(a))
#define scc(a) scanf("%lld", &(a))
#pragma comment (linker, "/STACK:5000000000")
typedef long long ll;

const ll mod = 998244353;
ll Inf = (ll)2e9;
ll LINF = (ll)1e18 + 1e17;

using namespace std;


void solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	fori(i, n)
		cin >> a[i];
	sort(all(a));
	ll x = 0, y = 0;
	int l = 0, r = n - 1;
	while (true)
	{
		if (r < l)
			break;
		x += a[r];
		r--;
		if (r < l)
			break;
		y += a[l];
		l++;		
	}
	cout << x * x + y * y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}

	return 0;
}
