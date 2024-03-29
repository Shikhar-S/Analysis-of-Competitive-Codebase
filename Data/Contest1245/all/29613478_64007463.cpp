#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define iiordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define MOD 1000000007
ll power(ll a,ll b, ll m=MOD)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res%m;
}
ll inverse(ll a,ll m=MOD)
{
    return power(a,m-2,m);
}
#define INFl 1e18
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define vii vector<ii>
#define vvii vector<vii>
#define F first
#define S second
#define forl(i,n) for(int i=0;i<n;i++)
#define fore(i,n) for(int i=1;i<=n;i++)
#define rforl(i,n)  for(int i=n-1;i>=0;i--)
#define rfore(i,n)  for(int i=n;i>=1;i--)
#define CASE(t) cout<<"Case #"<<(t)<<": ";
#define INF 1100000009
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define print(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cout<<it->F<<' '<<it->S<<endl;  
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
int main()
{
	fastio;
	string s;
	cin>>s;
	int n=s.size();
	string r;
	forl(i,n)
	{
		if(s[i]=='w' || s[i]=='m')
		{
			cout<<0<<endl;
			return 0;
		}
	}
	r=s;
	vi dp(100005,0);
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<dp.size();i++)
	{
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	int cnt=0;
	n=r.size();
	ll ans=1;
	if(r[0]=='u' || r[0]=='n')
		cnt=1;
	for(int i=1;i<n;i++)
	{
		if(r[i]==r[i-1] && (r[i]=='u'||r[i]=='n'))
			cnt++;
		else
		{
			if(cnt)
				ans*=dp[cnt];
			ans%=MOD;
			if(r[i]=='u' || r[i]=='n')
				cnt=1;
			else cnt=0;
		}
	}
	if(cnt)
		ans*=dp[cnt];
	ans%=MOD;
	cout<<ans<<endl;
}
