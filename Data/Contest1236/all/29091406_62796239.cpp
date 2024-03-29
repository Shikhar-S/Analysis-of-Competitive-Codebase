#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define popb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int,int>
#define piii pair <pii,int>
#define piiii pair <pii,pii>
#define plll pair <pair <ll, ll>, ll>
#define rep0(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define reprev(i,n) for(ll i=n;i>=0;i--)
#define all(c) c.begin(),c.end()
#define print(a) rep0(i,a.size()) cout << a[i] << " "
#define hi() cout << "\nHello, I am error. Can you find me? :):):)\n"
 
using namespace std;

const int mod = 1e9+7;
const long double pi = acos(-1);

unsigned ll power(unsigned ll x, unsigned ll y) 
{ 
	unsigned ll res = 1; 
	while(y > 0){
		if(y&1) res = (res * x) % mod;
		y = y >> 1;
		x = (x*x) % mod;
	}
	return res;
}

void solve(){

	int n;
	cin >> n;
	if(n%2 == 0){
		int count1 = 1, count2 = n*n;
		rep0(i,n){
			rep0(j,n){
				if(j<n/2){
					cout << count1 << " ";
					count1++;
				}else{
					cout << count2 << " ";
					count2--;
				}
			}
			cout << "\n";
		}
	}else{
		int a[n][n], count = 1;
		rep0(j,n){
			if(j%2 == 0){
				rep0(i,n){
					a[i][j] = count;
					count++;
				}
			}else{
				reprev(i,n-1){
					a[i][j] = count;
					count++;
				}
			}
		}
		rep0(i,n){
			rep0(j,n) cout << a[i][j] << " ";
			cout << "\n";
		}
	}

	return;
}

int main(){
 
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
 
	int TC = 1,t = 0;
	// cin >> TC;
	while(t++ < TC){
		solve();
		// cout << "\n";
	}
 
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
	return 0; 
}
