#include<bits/stdc++.h>
using namespace std;
#define MOD           998244853
#define C             1000000007
#define pi            acos(-1)
#define int           long long 
#define D             double
#define S             second
#define F             first
#define pb            push_back
#define ff            fflush(stdout)
#define ppb           pop_back
#define B(c)          (c).begin()
#define E(c)          (c).end()
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend()
#define SORT(v)       sort(ALL(v))  
#define lb            lower_bound
#define ub            upper_bound
#define si(c)         (int)((c).size())
#define L(c)           si(c)-1
#define gcd(a,b)      __gcd(a,b)
#define lcm(a,b)      (a*(b/gcd(a,b)))
#define sqr(a)        ((a) * (a))
#define optimize()    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define accuracy      cout << fixed << setprecision(18);
#define inf           (int)2e17
#define pow(i,n)      (int)pow((int)i,n)
typedef vector<int>                           vi;
typedef pair<int,int>                         pii;
typedef pair<int,pii>                         pipii;
typedef vector<vector<int> >                  vvi;
typedef map<int,int>                          mp;
typedef map<string,int>                       msi;
typedef priority_queue<pii, vector<pii>, greater<pii> > pq;
inline  bool checkBit(int n, int i) { return n&((int)1<<i); }
inline  int setBit(int n, int i) { return n|((int)1<<i);; }
inline  int resetBit(int n, int i) { return n&(~((int)1<<i)); }
inline  bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline  bool isLeapYear(int year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline  void normal(int &a) { a = (a+MOD)%MOD; }
inline  int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline  int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline  int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline  int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline  int modInv(int a) { return modPow(a, MOD-2); }
inline  int modDiv(int a,int b) { return modMul(a, modInv(b)); }
inline  int fact(int r){ int ans=1;while(r)ans=modMul(ans,r),r--;return ans; }
inline  int invfact(int r){int ans=1;while(r)ans=modMul(ans,modInv(r)),r--; return ans;}
inline  D dgcd(D a,D b){ if(a<b)return dgcd(b,a); if(b<.0001)return a; return dgcd(b,fmod(a,b));}



void solve(){
     int n;
     cin>>n;
     string s;
     cin>>s;
     int r=-1,l=inf;
     for(int i=0;i<n;i++){
          if(s[i]=='1')
          r=max(r,i),l=min(l,i);
     }
     int temp=0,ans=0;
     if(r!=-1)ans=max(2*(r+1),2*(n-l));
     for(int i=0;i<n;i++){
          if(s[i]=='1')temp+=2;
          else temp++;
     }
     cout<<max(ans,temp)<<endl;
}
 
signed main(){   
    optimize();       
    int t=1;
    //accuracy;
    //freopen("input.txt", "r", stdin);
    cin>>t;
    while(t--){
        solve();
    }
}
