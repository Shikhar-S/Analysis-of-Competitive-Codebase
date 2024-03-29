#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define ROF(i,a,b) for(ll i=a;i>=(ll)b;--i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define mp make_pair
#define INF (1ll << 40)

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  ll n;
  cin >> n;
  map<ll,ll> divs;
  for (ll i = 2; i*i <= n; ++ i) {
    while (n%i == 0) {
      divs[i] ++;
      n /= i;
    }
  }
  //cout << n << endl;
  if (n > 1) divs[n] ++;
  if (divs.size() == 1) {
    cout << divs.begin()->first << endl;
  } else cout << 1 << endl;

  return 0;
}
