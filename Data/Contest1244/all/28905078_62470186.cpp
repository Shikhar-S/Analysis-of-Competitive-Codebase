#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define endl "\n"
#define oo 0x3f3f3f3fLL
#define OO (oo*oo)
#define sz(s) (int)(s.size())
#define RT(s) return cout<<s,0
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define clr(v,val) memset(v,val,sizeof(v))
#define watch(x) cout<<(#x)<<" = "<<x<<endl
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> matrix;
const ld PI = acos(-1), EPS = 1e-8;
const int mod = 1000000007;
const int dr[]{ -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[]{ 0, 1, 1, 1, 0, -1, -1, -1 };
void run() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#else
	//freopen("input.in", "r", stdin);
#endif
}


int main() {
	run();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int l = -1, r = -1;
		for (int i = 0; i < n; i++)
			if (s[i] == '1') { l = i; break; }
		for (int i = n - 1; i  >= 0; i--)
			if (s[i] == '1') { r = i; break; }
		int rt = n;
		if (~l)
			rt = max(rt, max(l + 1, n - l) * 2);
		if (~r)
			rt = max(rt, max(r + 1, n - r) * 2);
		cout << rt << endl;
	}
}