#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;

#define all(x) (x).begin(), (x).end()
#define size(x) (ll)x.size()
#define x first
#define y second
#define chkmax(x, y) x = max(x, y)
#define chkmin(x, y) x = min(x, y)
#define pb emplace_back
#define od  (x) ((x)&1)
mt19937_64 gen;

int mod = 1e9 + 7;

int mul(int a, int b) {
  return (a * 1LL * b) % mod;
}


int binpow(int n, int k) {
  if (n < 0) n += mod;
  int res = 1;
  while (k) {
    if (k & 1) res = mul(res, n);
    n = mul(n, n);
    k >>= 1;
  }
  return res;
}

void run() {
  int n, m;
  cin >> m >> n;
  cout << binpow(binpow(2, n) - 1, m);
}

signed main() {
#ifdef kek
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  gen.seed(time(0));
#endif // kek
  ios::sync_with_stdio(0);
  cin.tie(0);
  run();
}
