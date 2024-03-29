#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 700 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll n , ans , l = 1 , r = 1 ;
string s , t ;
ll pr[N] , sf[N] , ps[N] ;


bool ok(ll x) {
	if (t[x] == ')') return 0 ;
	if (sf[x]  - (ps[x] - 1) < 0) return 0 ;
	ll res = ps[n - 1] - ps[x] + 1 ;
	res *= -1 ;
	if (pr[x - 1] < res) return 0 ;
	return 1 ;
}
ll calc() {
	fill(ps , ps + N , 0) ;
	fill(pr , pr + N , 0) ;
	fill(sf , sf + N , 0) ;
	if (t[0] == '(') ps[0] = pr[0] = 1 ;
	else ps[0] = pr[0] =  -1 ;
	for (int i = 1 ; i < n ; i ++) {
		if (t[i] == '(') ps[i] = ps[i - 1] + 1 ;
		else ps[i] = ps[i - 1] - 1 ;
		pr[i] = min(pr[i - 1] , ps[i]) ;
	}
	sf[n - 1] = ps[n - 1] ;
	for (int i = n - 2; i >= 0 ; i --) sf[i] = min(sf[i + 1] , ps[i]) ;
	ll res = 0 ;
	for (int i =1 ; i < n ; i ++) {
		res += ok(i) ;
	}
	ll ss = 0 ;
	ll x = 1 ;
	for (int i = 0 ; i < n ; i ++) {
		if (t[i] == '(') ss ++ ;
		else ss -- ;
		if (ss < 0) x = 0 ;
	
	}
	if (ss != 0) return 0 ;
	return res + x ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n >> s ;
    ll k = 0 ;
    for (int i = 0 ; i < n ; i ++) {
    	for (int j = i ; j < n ; j ++) {
    		t = s ;
    		if (t[i] == t[j] && k) continue ;
    		if (t[i] == t[j]) k ++ ;
    		swap(t[i] , t[j]) ;
    		t += t ;
    		ll tmp = calc() ;
    		if (tmp >= ans) {
    			ans = tmp ;
    			l = i + 1 ;
    			r = j + 1; 
			}
		}
	}
	cout << ans << '\n' << l << ' ' << r; 
    return (0) ;
}
