
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define c(P)        cout<<P<<"\n"
#define dbg(P)      cout<<P<<" "
#define pii         pair<ll,ll>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define F           first
#define S           second
#define mem(a,val)  memset(a,val,sizeof(a))
#define fr(i,x,n)   for(ll i=x;i<n;i++)
#define frr(i,x,n)  for(ll i=n-1;i>=x;i--)


const ll N   =  100005;
const ll mod = 1e9 + 7;

using namespace std;


  ll a[N];
void solve()
{
  a[1] =2;
  a[2] =4;
for (int i = 3; i < N; ++i)
{
  a[i] = (a[i-1] + a[i-2])%mod;
}
  ll n,m,k,x=0,y=0,c=0,q,ans=0;
  cin>>n>>m;
  c+=a[m];
  for (int i = n; i >1 ; --i)
  {
    c+= a[i]-a[i-1];
    if(c<0)
    c+=mod;
    if(c>mod)
    c-=mod;   
  }
  cout<<c<<"\n";
}

signed main(){
      #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
      #endif
      ios_base::sync_with_stdio(false);   
      cin.tie(NULL);

      ll T=1;
      //cin>>T;
      while(T--)
      {
      solve();
      }
      return 0;
    }
