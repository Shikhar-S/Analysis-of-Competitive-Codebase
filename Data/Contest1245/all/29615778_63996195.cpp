#pragma comment(linker, "/STACK:134217728")
#pragma GCC optimize("fast-maths")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <climits>
#include <ctime>
#include <random>
using namespace std;

#define forx(_name,_from, to, value) for (int name = from; name < to; name += value)
#define rforx(_name, from, to, value) for (int name = from; name > to; name -= _value)
#define all(_STL_NAME) _STL_NAME.begin(), _STL_NAME.end()
#define rall(_STL_NAME) _STL_NAME.rbegin(), _STL_NAME.rend()
#define mp(_FIRST,_SECOND) make_pair(_FIRST,_SECOND)

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
const ld eps = 1e-12;
mt19937 rndm;

void start() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20); cout.setf(ios::fixed);
	string FILENAME = "navalny";
	rndm.seed(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#else
	//freopen((FILENAME + ".in").c_str(), "rt", stdin);
	//freopen((FILENAME + ".out").c_str(), "wt", stdout);
#endif
}

inline int FastIn(FILE* streamin = stdin) {
	char c = ' ';
	bool mns = false;
	int a = 0;
	while (!isdigit(c)) {
		mns = c == '-';
		c = _getc_nolock(streamin);
	}
	while (isdigit(c)) {
		a *= 10;
		a += c - '0';
		c = _getc_nolock(streamin);
	}
	return (mns ? -a : a);
}

inline void FastOut(int val, FILE* streamout = stdout) {
	if (val < 0) {
		val = -val;
		_putc_nolock('-', streamout);
	}
	bool fst = true;
	const int degree = 1000000000;
	for (int i = degree; i > 0; i /= 10) {
		int dl = val / i;
		if (dl || !fst) {
			_putc_nolock('0' + dl, streamout);
			fst = false;
		}
		val %= i;
	}
	if (fst)
		_putc_nolock('0', streamout);
	_putc_nolock('\n', streamout);
}

int gcd(int a, int b) {
	while (a) {
		b %= a;
		swap(a, b);
	}
	return b;
}

int main() {
	start();
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (gcd(a, b) != 1)
			cout << "Infinite";
		else
			cout << "Finite";
		cout << '\n';
	}
	return 0;
}