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

#define N  4000005
ll edges;
ll n;
ll x[2005],y[2005],c[2005],k[2005];
vector<pair <ll,pii>> edgelist;
vi par(2005),siz(2005,1);
vi ans;
vector <pii> ans1;
ll find(ll x)
{
	while(x!=par[x]) x=par[x];
	return x;
}
bool same(ll i,ll j)
	{return find(i)==find(j);}
void unite(ll a,ll b)
{
	a=find(a);
	b=find(b);
	if(siz[a]<siz[b]) swap(a,b);
	siz[a]+=siz[b];
	par[b]=a;
}
long long kruskal()
{
    ll x, y;
    long long cost, minimumCost = 0;
    sort(all(edgelist));
    for(ll i = 0;i < n*n+n;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = edgelist[i].S.F;
        y = edgelist[i].S.S;
        cost = edgelist[i].F;
        // Check if the selected edge is creating a cycle or not
        if(!same(x,y))
        {
        	if(x==0||y==0){
        		if(x) ans.pb(x);
        		else ans.pb(y);
        	}
        	else ans1.pb({x,y});
            minimumCost += cost;
            unite(x, y);
        }    
    }
    return minimumCost;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		cin>>n;
		rep(i,1,n+1) cin>>x[i]>>y[i];
		rep(i,1,n+1) cin>>c[i],edgelist.pb({c[i],{0,i}});
		rep(i,1,n+1) cin>>k[i];
		rep(i,1,n+1) rep(j,1,n+1) {
			edgelist.pb({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),{i,j}});
		} 
		rep(i,0,n+1) par[i]=i;
		cout<<kruskal()<<endl;
		cout<<sz(ans)<<endl;
		for(auto i:ans)cout<<i<<' ';
			cout<<endl;
		cout<<sz(ans1);
		cout<<endl;
		for(auto i:ans1) cout<<i.F<<' '<<i.S<<endl;

	}
	return 0;
}