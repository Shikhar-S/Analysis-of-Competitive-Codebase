#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e3+50;
const int mod=1e9+7;
using namespace std;
int t,i,n,mx;
char c[nmax];
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		mx=n;
		for(i=1;i<=n;i++)cin>>c[i];
		for(i=1;i<=n;i++)
		{
			if(c[i]=='0')continue;
			mx=max(mx,2*i);
			mx=max(mx,2*(n-i+1));
		}
		cout<<mx<<'\n';
	}
	return 0;
}
