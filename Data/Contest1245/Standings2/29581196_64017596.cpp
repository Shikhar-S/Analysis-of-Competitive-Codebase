/* winners never quit and quitters never win.
      #swap                                 */
      
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000000;
const ll rk = 256;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)
struct vertex
{
    ll l=0;
    ll r=0;
    ll parent=-1;
    ll size=1;
    ll cost=0;
    ll k=0;
};
ll find(vertex x[],ll sor)
{
    if(x[sor].parent==-1)
        return sor;
    return x[sor].parent=find(x,x[sor].parent);
}
void join(vertex x[],ll u,ll v)
{
    ll uset=find(x,u);
    ll vset=find(x,v);
    if(x[uset].size<x[vset].size)
    {
        x[vset].parent=uset;
        x[uset].size+=x[vset].size;
    }
    else
    {
        x[uset].parent=vset;
        x[vset].size+=x[uset].size;
    }
}

 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    ll n;
    cin>>n;
    vertex x[n+1];
    rep(a,0,n)
        cin>>x[a+1].l>>x[a+1].r;
    vc<pair<ll,pll>> edges;
    rep(a,0,n)
    {
        cin>>x[a+1].cost;
        edges.pb({x[a+1].cost,{0,a+1}});
    }
    rep(a,1,n+1)
        cin>>x[a].k;
    
    rep(a,1,n+1)
    {
        rep(b,a+1,n+1)
        {
            ll tot=llabs(x[a].l-x[b].l)+llabs(x[a].r-x[b].r);
            edges.pb({(x[a].k+x[b].k)*tot,{a,b}});
        }
    }
    sort(all(edges));
    ll ans=0;
    vc<ll> sor;
    vc<pll> edge;
    for(auto y:edges)
    {
        ll cc=y.fs,u=y.sec.fs,v=y.sec.sec;
        
        if(find(x,u)!=find(x,v))
        {
            if(u==0)
                sor.pb(v);
            else if(v==0)
                sor.pb(u);
            else
                edge.pb({u,v});
            join(x,u,v);
            ans+=cc;
        }
    }
    
    cout<<ans<<endl;
    cout<<sor.size()<<endl;
    for(auto y:sor)
        cout<<y<<" ";
    cout<<endl;
    cout<<edge.size()<<endl;
    for(auto y:edge)
        cout<<y.fs<<" "<<y.sec<<endl;
    
	return 0;
}