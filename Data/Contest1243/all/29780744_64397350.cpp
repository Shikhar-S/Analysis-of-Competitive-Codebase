#include<bits/stdc++.h>
//#define m 1000000007
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define debug cout << "Hold right there sparky.....\n";
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;
 
typedef long long int ll;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

 #define int ll
ll mod=1e12;
        ll mod1=1e9+5;
        ll power(ll a,ll b)
        {
            if(b==0) return 1;
            else if(b%2==0)
                return power((((a%mod)*(a%mod))%mod),b/2)%mod;
            else return ((a%mod)*(power((((a%mod)*(a%mod))%mod),b/2)%mod))%mod;
        }
      

int32_t main()
{
    #ifndef ONLINE_JUDGE
   
    freopen("input.txt", "r", stdin);
   
    freopen("output.txt", "w", stdout);
#endif
        
    int n;
    cin >> n;
    vector<int>del;
    for(int i=2; i*i<=n; i++)
        if (n%i == 0) {
            del.push_back(i);
            if (i * i != n)
                del.push_back(n / i);
        }
    del.push_back(n); 
    int ans = 0;
    for(int i=0;i<del.size();++i)
        ans = __gcd(ans, del[i]);
    cout << ans << endl;

        


      
}

