#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
  if (y > x) x = y;
#define amin(x, y) \
  if (y < x) x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
  if (f) yes else no;
#define noo \
  { no return; }

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
  vector<T> a = vector<T>(n + oneIndexed);

  for (ll i = 0; i < n; i++) {
    T p;
    cin >> p;
    a[i + oneIndexed] = p;
  }

  return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i] << " ";
  }
  cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i].first << " " << a[i].second << endl;
  }
}

void solve() {
  ll n, m;
  cin >> n;
  vector<ll> arr = ga(n);
  cin >> m;
  vector<ll> a = ga(m);
  set<ll> st;
  map<ll, ll> mp;
  for (ll i = 0; i < n; i++) {
    // st.insert(arr[i]);
    mp[abs(arr[i]) % 2]++;
  }
  ll c = 0;
  for (ll i = 0; i < m; i++) {
    if (mp.find(abs(a[i]) % 2) == mp.end()) {
      continue;
    } else {
      c += mp[abs(a[i]) % 2];
    }
  }
  cout << c << '\n';
  // code
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) solve();
  return 0;
}