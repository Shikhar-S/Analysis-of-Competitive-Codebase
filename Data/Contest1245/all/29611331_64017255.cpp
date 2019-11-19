/*
Author : Puneet Rai
Team : BlundersPride
Date : 01-11-2019
Time : 20:37:24
*/


#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define vld vector< ld >
#define vvld vector< vld >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define endl "\n"
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define scd second

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;

////////////////////////////////////////////////////////////////// Inputs ////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void read(T &x){
	cin >> x;
}

template <typename T , typename T0>
void read(T &x,T0 &y){
	cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x,T0 &y,T1 &z){
	cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x,T0 &y,T1 &z,T2 &w){
	cin >> x >> y >> z >> w;
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
	cin >> p.fst >>p.scd;
}

template <typename T>
void read(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}

template <typename T>
void read(T oneD[] , ll n){
	for(ll i=0;i<n;i++){
		read(oneD[i]);
	}
}

/////////////////////////////////////////////////////////////////////////// Outputs ////////////////////////////////////////////////////////////////////////////

template <typename T>
void write(T &x){
	
	cout << x << " ";
}

template <typename T , typename T0>
void write(T &x,T0 &y){
	cout << x << " " << y << "\n";
}

template <typename T , typename T0 , typename T1>
void write(T &x,T0 &y,T1 &z){
	cout << x << " " << y << " " << z << "\n";
}

template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x,T0 &y,T1 &z,T2 &w){
	cout << x << " " << y << " " << z << " " << w << "\n";
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
	write(p.fst);
	write(p.scd);
	cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T>
void write(T oneD[] ,ll n){
	for(ll i=0;i<n;i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
	for(auto it : mpp){
		write(it.fst);
		cout << ": ";
		write(it.scd);
		cout << "\n";
	}
	cout<<endl;
}

///////////////////////////////////////////////////////////////////////// Maths //////////////////////////////////////////////////////////////////////////////

vll sieve;
void Sieve(ll N){
	const ll maxn = N;
	sieve.resize(maxn);
	forn(i,maxn) sieve[i] = i;
	sieve[1] = -1;
	sieve[0] = -1;
	forab(i,2,maxn,1) if(i == sieve[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(sieve[j] == j) sieve[j] = i;
}


ll extended_GCD(ll a , ll b , ll &x , ll &y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1 , y1;
	ll gcd = extended_GCD(b%a , a , x1 , y1);
	x = y1 - (b/a)*x1; 
	y = x1;
	return gcd;
}

ll power(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a , ll mod = MOD){
	ll x , y;
	extended_GCD(a , mod , x , y);
	if(x < 0) x += mod;
	return x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll dist(pair<ll,ll> a , pair<ll,ll> b) {
	return abs(a.fst - b.fst) + abs(a.scd - b.scd);
}

void solve(){
	ll n;
	cin >> n;
	vector<pair<ll , ll> > C(n+1);
	for(ll i = 1 ; i <= n ; ++i) {
		cin >> C[i].fst >> C[i].scd;
	}
	multiset<pair<ll , pair<ll , ll> > > S;
	
	vector<ll> c(n+1 , 0);
	for(ll i = 1 ; i <= n ; ++i) {
		cin >> c[i];
		S.insert({c[i] , {i , 0}});
	}
	vector<ll> k(n+1 , 0);
	for(ll i = 1 ; i <= n ; ++i) {
		cin >> k[i];
	}
	vector<ll> vis(n+1 , 0);
	vis[0] = 1;
	ll ans = 0;
	vector<pair<ll , ll> > edge;
	while(!S.empty()) {
		ll cost = S.begin()->fst;
		ll u = S.begin()->scd.fst;
		ll v = S.begin()->scd.scd;
		S.erase(S.begin());

		if(vis[u] == 1) {
			continue;
		}
		vis[u] = 1;
		ans += cost;
		edge.pb({u , v});

		for(ll i = 1 ; i <= n ; ++i) {
			if(vis[i] == 1) continue;
			ll curCost = (k[i] + k[u]) * dist(C[i] , C[u]);
			S.insert({ curCost , {i , u} });
		}
	}
	vector<ll> P;
	ll e = 0;
	for(auto x: edge) {
		if(x.scd == 0) {
			P.pb(x.fst);
		} else {
			e++;
		}
	}
	cout << ans << endl;
	cout << P.size() << endl;
	for(auto x: P) {
		cout << x << " ";
	}
	cout << endl << e << endl;
	for(auto x: edge) {
		if(x.scd != 0) {
			cout << x.fst << " " << x.scd << endl;
		}
	}
}

int main()
{	
	flash
	solve();
    return 0;
}
