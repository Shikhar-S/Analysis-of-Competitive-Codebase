#include"bits/stdc++.h"
using namespace std;
#define ld long double
#define int long long
#define pb push_back 
#define Z(c) (int)(c).size()
#define L(c) c[Z(c)-1]
#define F first
#define S second
#define nl "\n"
#define mii map<int,int> 
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define rep(i,iv,n) for(int (i)=(iv);(i)<(n);(i)++)
#define D1(x) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<nl
#define D2(x,y) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<nl
#define D3(x,y,z) cerr <<"At line "<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<nl
#define tr(it,ct) for(auto &(it) : (ct))

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > pii;
typedef vector< pii > vp;
void swap(int &a,int &b)
{ auto tm=a; a=b; b=tm; }
 
  //Take care of duplicates

  const int mod=1000000007;
  const int mod2=998244353;
  const int INF=(1LL<<50)-1;
  const int N=2e5+25; 
  
  void bheja_fry()
  { 
     int n; cin>>n;
      
     vi v;
     for(int i=2;i*i<=n;i++)
     {  
       if(n%i==0)
      {   v.pb(i);
        while(n%i==0)
        {
          n=n/i;
        }

       }
     }
     if(n!=1) v.pb(n);

     if(Z(v)==1)
      cout<<v[0];
     else
      cout<<1;
  }

signed main()
{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r", stdin); 
   freopen("output.txt","w", stdout);
   freopen("error.txt","w", stderr);
   #endif

  
   int t=1;                         
//   cin>>t;
  rep(i,1,t+1)
  { // cout<<"Case #"<<i<<": ";
   bheja_fry();
//   if(i<t)
//   cout<<nl;
  }
  
  #ifndef ONLINE_JUDGE
  cerr<<(1000*clock())/CLOCKS_PER_SEC<<"ms";
  #endif
 return 0; 
}