// I can't tell you what it really is,
// I can only tell you what it feels like.
#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int >
#define E cout << '\n'

const int mod = 1e9 + 7;
const int N = 4e5 + 5;

int a[N];
 
inline void solve() {
   int a, b, c, d, k;
   cin >> a >> b >> c >> d >> k;
   int x = a / c + (a%c!=0);
   int y = b / d + (b%d !=0);
   if (x + y > k) {
   	cout << "-1\n";
   	return;
   }
   cout << x << ' ' << y << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t; while(t--)
  solve();
  return 0;
}