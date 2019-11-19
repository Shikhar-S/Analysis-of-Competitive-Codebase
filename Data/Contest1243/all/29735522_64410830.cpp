//katana_handler
//shakalaka_boom_boom
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define ordered_set_pll tree <pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree <ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//query 1 order_of_key (k) : Number of items strictly smaller than k .
//query 2 find_by_order(k) : K-th element in the set (counting from zero).
//less<ll> means query 1 will return numbers strictly less than k
//greater<ll> means query 1 will return numbers strictly greater than k
#define		pb				push_back
#define		pf				push_front
#define		MOD				1000000007
#define		popb			pop_back
#define		popf			pop_front
#define		len(x)			x.size()    
#define		MAXN			100001
#define		mp				make_pair
#define		endl			'\n'
#define		ff				first
#define		ss				second
#define		tt				third
#define		mapcl			map<char,ll>
#define		mapll			map<ll,ll>
#define		cmp				complex<double>
#define		pi				3.141592653589793238462643383279502884197169399375105820974944592307816406286 
#define		inf				LLONG_MAX
#define		flush			fflush(stdout)
#define		vll				vector<ll>
#define		all(v)			v.begin(),v.end()
#define		fr(i,z,n)		for(ll i=z;i<n;i++)
#define		sqrt			sqrtl
#define		cbrt			cbrtl
typedef		long long		ll;
typedef		pair<ll,ll>		pll;
typedef		long double		ld;
ll 			power(ll a,ll b,ll mod)			{if(b==0)return 1;ll tmp=power(a,b/2,mod);tmp=(tmp*tmp)%mod;if(b&1)tmp=(tmp*a)%mod;return tmp;}
ll 			mandist(pll a,pll b)			{return abs(a.ff-b.ff)+abs(a.ss-b.ss);}
bool		coll(pll p1,pll p2,pll p3)		{if((p3.ss-p2.ss)*(p2.ff-p1.ff)==(p2.ss-p1.ss)*(p3.ff-p2.ff))return true;else return false;}
void		print(auto x)					{cout<<x<<endl;}
void		pv(vector<auto> v)				{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void		pv1(vector<auto> v)				{for(ll i=1;i<(ll)v.size();i++)cout<<v[i]<<" ";cout<<endl;}
void		pset(set<auto> v)				{for(auto x:v)cout<<x<<" ";cout<<endl;}
void		pvsl(vector<auto> v)			{for(ll i=0;i<(ll)v.size();i++)cout<<v[i]<<" ";}
void		in(vector<auto> &v, ll n)		{v.resize(n);for(ll i=0;i<n;i++)cin>>v[i];}
void		in1(vector<auto> &v, ll n)		{v.resize(n+1);for(ll i=1;i<=n;i++)cin>>v[i];v[0]=0;}
void		sortv(auto &v)					{sort(v.begin(),v.end());}
void		fast()							{ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
double		dist2d(pll a,pll b)				{ll x=abs(a.ff-b.ff);ll y=abs(a.ss-b.ss);return (sqrt((x*x)+(y*y)));}
//all variables and functions below this line
const int MAX_N = 2e5 + 10;
 
int n, m, cc = 1;
vector <int> ans;
unordered_set <int> nodes;
set <int> G[MAX_N];
 
void dfs (int u) {
  ans.back()++;
  vector <int> st;
  for (int v: nodes) if (G[u].count(v) == 0) st.push_back(v);
  for (int v: st) nodes.erase(v);
  for (int v: st) dfs(v);
}
 
int main () {
  cin>>n>>m;
  for (int i = 1; i <= n; i++) nodes.insert(i);
  while (m--) {
    int u, v;
   cin>>u>>v;
    G[u].insert(v);
    G[v].insert(u);
  }
  for (int u = 1; u <= n; u++) if (nodes.count(u)) nodes.erase(u), ans.push_back(0), dfs(u);
  ll ANS=ans.size();
  cout<<ANS-1<<endl;

}
