/*
  I_🧡🧡🧡_QMsh
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

template <typename T> void smin(T &a, const T &b) { a = (a < b ? a : b); }
template <typename T> void smax(T &a, const T &b) { a = (a > b ? a : b); }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

signed main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll n, p, w, d;
  cin >> n >> p >> w >> d;

  for (ll i = 0; i <= w; i++)
  {
    ll o = p - i * d;
    if (o >= 0 && o % w == 0 && i + o / w <= n)
    {
      return cout << o / w << " " << i << " " << n - i - o / w, 0;
    }
  }
  cout << -1;

  return 0;
}