#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define int long long
#define M 1000000007
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)

const int N = 100007;

void init()
{

}

void solve()
{
	int i, j, k, n, m, q;
	int x, y, l, r;
	int a, b, c, d;
	string s;
	cin >> n;
	cin >> s;
	int ans = n;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			int x = i+1, y = n-x;
			ans = max(ans, max(2*x, max(2*y + 2, x+y+1)));
		}
	}
	cout << ans << endl;
}

int32_t main()
{
	fastio;
	int t;
	cin >> t;
	for(int pp=1;pp<=t;pp++){
		solve();
	}
	return 0;
}