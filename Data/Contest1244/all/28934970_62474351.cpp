#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

ll n, p, w, d, x, y, t, a, b, ans;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p>>w>>d;
	ll g=__gcd(d, w);
	if (p%g) kill(-1)
	p/=g;
	w/=g;
	d/=g;
	
	for (ll y=0; y<w; y++){
		ll pp=p-y*d;
		if (pp%w || pp<0) continue ;
		ll x=pp/w;
		if (x+y>n) continue ;
		if (x<0 || y<0 || x*w+y*d!=p) continue ;
		cout<<x<<' '<<y<<' '<<n-x-y<<'\n';
		return 0;
	}
	
	kill(-1)
	
	return 0;
}

