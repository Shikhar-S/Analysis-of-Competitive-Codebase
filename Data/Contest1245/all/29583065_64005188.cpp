/* ****revpro**** */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl	   '\n'
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)    
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mii	    map<ll,ll>
using namespace std;

#define N  100005
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{
		int n;
		cin>>n;
		string s;
		int a[3]={0};
		rep(i,0,3)cin>>a[i];
		cin>>s;
		int b[3]={0};
		rep(i,0,n) {
			char x=s[i];
			if(x=='R') b[0]++;
			else if(x=='P') b[1]++;
			else b[2]++;
		}
		ll ans=0;
		ll c[3];
		ll ex[3];
		rep(i,0,3) c[i]=min(a[i],b[(i+2)%3]),ans+=min(a[i],b[(i+2)%3]);
		rep(i,0,3) ex[i]=a[i]-c[i];
		map <char,int> m;
		map <int,char> m1;
		m['R']=0;
		m['P']=1;
		m['S']=2;
		m1[0]='R';
		m1[1]='P';
		m1[2]='S';
		if(ans>=(n+1)/2) {
			cout<<"YES\n";
			rep(i,0,n){
				if(c[(m[s[i]]+1)%3]) {
					cout<<m1[(m[s[i]]+1)%3];
					c[(m[s[i]]+1)%3]--;
				}
				else {
					rep(j,0,3) {if(ex[j]) {ex[j]--;cout<<m1[j];break;}}
			}
		}
			cout<<endl;
		}
		else {
			cout<<"NO\n";
		} 
	}
	return 0;
}