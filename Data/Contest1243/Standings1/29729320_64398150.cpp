/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define INF 1000000000  
#define MOD 1000000007
#define MO 1000000006
#define M 998244353
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modExpo((x*x)%MOD,n/2);
    else                             //n is odd
        
        return (x*modExpo((x*x)%MOD,(n-1)/2))%MOD;

}
ll modInverse(ll n) 
{ 
    return modExpo(n,MOD-2); 
}
#define N 1000005
//Variables Start   
ll n,m,k,ar[N],br[N];
string s,s1;
//Variables End
ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}
int main()
{
    ios
    int ti=1;
    cin>>ti;
    while(ti--)
    {
        cin>>n;
        cin>>s>>s1;
        vi pos;
        map<char,int> ma;
        rep(i,0,n)
        {
            if(s[i]!=s1[i])pos.pb(i);
            ma[s[i]]++;
            ma[s1[i]]++;
        }
        bool ok=true;
        for(auto i:ma)
        {
            if(i.S&1)
            {
                ok=false;
                break;
            }
        }
        if(!ok)
        {
            cout<<"No"<<endl;
            continue;
        }
        vpii ans;
        rep(i,0,pos.size())
        {
            if(s[pos[i]]==s1[pos[i]])continue;
            rep(j,i+1,pos.size())
            {
                if(s[pos[j]]==s[pos[i]])
                {
                    ans.pb(mp(pos[j],pos[i]));
                    s[pos[j]]=s1[pos[i]];
                    break;
                }
                if(s1[pos[j]]==s[pos[i]])
                {
                    ans.pb(mp(pos[j],pos[j]));
                    swap(s[pos[j]],s1[pos[j]]);
                    ans.pb(mp(pos[j],pos[i]));
                    s[pos[j]]=s1[pos[i]];
                    break;

                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<ans.size()<<endl;
        for(auto i:ans)cout<<i.F+1<<" "<<i.S+1<<endl;        
    }
    return 0;
        
}