#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define pb push_back
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inp(n) for(i=0;i<n;i++) cin>>A[i];
#define inz(A) memset(A,0,sizeof(A))
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define T 1000000
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define vp vector<pair< int,int> >
#define mpi map<pair<int,int> ,int>
#define mip map<int, pair<int,int> >
#define inf INT_MAX
#define inf1 LONGLONG_MAX
#define sz(v) v.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<#x<<"is "<<x<<endl;
#define lower(s) transform(all(s),s.begin(),::tolower)
#define endl "\n"
vector<int>adj [T];
			/*brownsands IIITA*/
int power(int a,int x){a%=mod;
              int res=1;
		while(x>0){
		if(x&1)
		res=res*a%mod;
		a=a*a%mod;
                    x>>=1;  }
		return res;}
void solve()
{	int n,m,a,b;
	cin>>n>>m;
	a=power(2,m)%mod;
	a=(a-1+mod)%mod;
	b=power(a,n)%mod;
	cout<<b<<endl;
}
signed main()
{
   boost
        int test=0,t;
		//cin>>t;
		t=1;
		while(test++ <t){
            //cout<<"Case "<<test<<": ";
            solve();
            //cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
               }		
} 
               
			
 

				
		
		


