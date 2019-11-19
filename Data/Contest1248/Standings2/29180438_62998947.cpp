#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define debug1(a) cout<<" "<<#a<<" : "<<a<<"\n"
#define debug2(a,b) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<"\n"
#define debug3(a,b,c) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<"\n"
#define debug4(a,b,c,d) cout<<" "<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<"\n"
#define INF (int)10000000000000000
#define PI (double)3.14159265358979
// #define M 421412341324321
#define MOD 1000000007

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin>>n>>m;
	if (n<m) swap(n,m);
	int a[n+1] = {0};

	a[0] = 2;
	a[1] = 2;

	REP(i,2,n)
	{
		a[i] = (a[i-1]+a[i-2])%MOD;
		// debug2(i,a[i]);
	}
	int b[m+1] = {0};
	b[0] = 2;
	b[1] = a[n];
	// debug2(b[0], b[1]);
	// rep(i,n+1) debug1(a[i]);
	REP(i,2,m)
	{
		b[i] = (b[i-1]+a[i-2])%MOD;
	}
	cout<<b[m];



	return 0;
}