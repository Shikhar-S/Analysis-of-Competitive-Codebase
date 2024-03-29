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
//	cin>>TESTS;
	while(TESTS--)
	{
		string s;
		cin>>s;
		ll n=sz(s);
		if(s[0]=='w'||s[0]=='m'){
			cout<<0;
			return 0;
		}
		ll dp[n+1]={0};
		dp[1]=1;
		dp[0]=1;
		rep(i,1,n){

		if(s[i]=='w'||s[i]=='m'){
			cout<<0;
			return 0;
		}
			if((s[i]==s[i-1])&&(s[i]=='u')) dp[i+1]=(dp[i]+dp[i-1])%hell;
			else if((s[i]==s[i-1])&&(s[i]=='n')) dp[i+1]=(dp[i]+dp[i-1])%hell;
			else dp[i+1]=dp[i];
		}	
		cout<<dp[n];
	}
	return 0;
}