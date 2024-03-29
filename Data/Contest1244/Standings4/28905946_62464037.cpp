#include <bits/stdc++.h>
namespace myland{
    using namespace std;
    namespace _abbr{
        #define fi first
        #define se second
        #define pb push_back
        #define pr make_pair
        #define lb lower_bound
        #define ub upper_bound
        #define str string
        #define _1s __builtin_popcountll
        #define nth(a,l,r,k) nth_element(a+l,a+l+k-1,a+r+1)
        typedef unsigned int ui;
        typedef long long ll;
        typedef unsigned long long ull;
        typedef double db;
        typedef long double ld;
        typedef pair<int,int> pii;
        typedef pair<ll,ll> pll;
        typedef vector<int> vi;
        typedef vector<ll> vl;
        typedef vector<pii> vpii;
        typedef vector<pll> vpll;
        typedef vector<vi> vvi;
        typedef vector<vl> vvl;
        typedef vector<vpii> vvpii;
        typedef vector<vpll> vvpll;
    }using namespace _abbr;
    namespace _constant{
        const double EPS(1e-8);
        const double PI(acos(-1.0));
        const int INF(0x3f3f3f3f);
        const ll INFL(0x3f3f3f3f3f3f3f3fll);
        const int MOD(1e9+7);//998244353, 16341163, 999983, 131, 1e9 + 9
        const int dx[]={1,0,0,-1,-1,1,1,-1}, dy[]={0,-1,1,0,1,1,-1,-1};
    }using namespace _constant;
    namespace _solve{
        #define XOR int main()
        #define GG exit(0)
        #define rep(x,a,b) for(int x=a;x<=b;++x)
        #define per(x,a,b) for(int x=b;x>=a;--x)
        #define times(x) for(int cas=1,tms=(x);cas<=tms;++cas)
        #define CaseT int T;cin >> T;times(T)
        #define TCase int T;scanf("%d",&T);times(T)
        #define continue(_) if(_) continue;
        #define break(_) if(_) break;
    }using namespace _solve;
    namespace _calculate{
        bool odd(ll x){return x&1;}
        bool even(ll x){return (x&1)^1;}
        bool posi(ll x){return x>0;}
        bool nega(ll x){return x<0;}
        bool zero(ll x){return x==0;}
        bool prime(ll x){if(x<2) return 0;
            for(ll i=2;1ll*i*i<=x;i++) if(x%i==0) return 0;
            return 1;}
        ll droot(ll x){return 1+(x-1)%9;}
        ll upd(ll a, ll b){return a%b?a/b+1:a/b;};
        ll gcd(ll a, ll b){return __gcd(a, b);}
        ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
        mt19937_64 rand(time(0));
        ll random(ll a, ll b){return a+rand()%(b-a+1);};
        ll bitn(ll x){ll c=0;while(x)c++,x>>=1;return c;}
        template<class T>T sqr(T x){return x*x;}
        ll qpow(ll a, ll n, ll mod = MOD){
            ll res(1);while(n){
            if(n&1) (res*=a)%=mod;
            (a*=a)%=mod;n>>=1;}
            return res%mod;}
        ll inv(ll a, ll mod = MOD){return qpow(a,mod-2, mod);}
        template<class T>void tomin(T& a,T b){if(b<a) a=b;}
        template<class T>void tomax(T& a,T b){if(b>a) a=b;}
    }using namespace _calculate;
    namespace _simple_algo{
        #define rg(a,x,y) (a+x), (a+y+1)
        #define vrg(a,x,y) (a.begin()+x),(a.begin()+y+1)
        #define all(x) (x).begin(),(x).end()
        #define rall(x) (x).rbegin(),(x).rend()
        #define clr(a,b) memset(a,b,sizeof(a))
        #define fil(a,b) fill(all(a),b)
        #define _sum(a) accumulate(a, 0ll)
        #define sz(a) (ll(a.size()))
        ll sol(const string& s){ll x=0;
            for(char c:s)x=x*10+c-48;return x;}
        string los(ll x){string s = "";
            if(x==0) return "0";
            while(x) s=char(x%10+48)+s,x/=10;
            return s;}
        bool pal(const string& s){int l = s.size();
            for(int i=0,j=l-1;i<j;i++,j--)
                if(s[i]!=s[j]) return 0;return 1;}
    }using namespace _simple_algo;
    namespace _io{
        #define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        #define bug cerr << "!!!" << endl;
        #define bugc(_) cerr << (#_) << " = " << (_) << endl;
        template<class T>void rd(T& x){cin>>x;}
        str srd(){str s;cin>>s;return s;}
        ll rd(){
            ll x=0,f=1;char ch=getchar();
            while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
            while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
            return x*f;}
        void rd(int& x){x=rd();}
        void rd(ll& x){x=rd();}
        template<class A,class B>void rd(A& a,B& b){rd(a), rd(b);}
        template<class A,class B>void rd(pair<A,B>& p){rd(p.fi, p.se);}
        template<class A,class B,class C>void rd(A& a,B& b,C& c){rd(a,b);rd(c);}
        template<class T>void wt(const T& x){cout << x << '\n';}
        template<class T>void wt(const T& x, char c){cout << x << c;}
        template<class T>void wt(const T& x, const str& s){cout << x << s;}
        template<class T>void wt(const T& x, int rnd){
            cout << fixed << setprecision(rnd) << x << '\n';}
        template<class T>void wt(const vector<T>& v){
            for(int i=0;i<sz(v);i++){cout << v[i];if(i<sz(v)-1) cout << ' ';};wt("");}
        template<class A,class B>void wt(const pair<A,B>& pr){
            cout << pr.fi << ' ' << pr.se << '\n';}
        #define out(_) wt(_),GG
    }using namespace _io;
}using namespace myland;

XOR {
    TCase {
        ll a = rd(), b = rd(), c = rd(), d = rd(), k = rd();
        ll ans = upd(a, c) + upd(b, d);
        if (ans > k) wt(-1); else wt(pr(upd(a, c), upd(b, d)));
    }
}