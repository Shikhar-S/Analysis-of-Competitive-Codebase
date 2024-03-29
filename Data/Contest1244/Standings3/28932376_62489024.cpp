#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
#include<unordered_map> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include "boost/algorithm/string.hpp"
#define fio ios_base::sync_with_stdio(false)
#define mod 1000000007
#define mod1 mod
#define mod2 1000000007
#define li long long int
#define ll li
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN 1000000000000000005
#define MINN -1000000000000000000
#define INTMAX 1000001000
#define pii pair<ll,ll> 
#define pdd pair<double,double>
#define pic pair<int,char>
#define N 300005
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535
#define lgn 20
 
 
// #define INTMAX 200000000 
 
// using namespace boost;
// #define si short int
 
using namespace std;
using namespace __gnu_pbds;             
typedef priority_queue<ll, vector<ll > > max_pq;
typedef priority_queue<ll, vector<ll> , greater<ll>  > min_pq;
ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
 
// using namespace __gnu_pbds;         
// typedef priority_queue<pair<ll,char> , vector<pair<ll , char> > > max_pq;
// typedef priority_queue<pii , vector<pii > ,greater<pii > > min_pq;
typedef tree<pii , null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;
// typedef priority_queue<pair < ll , pair < pii , ll > >  , vector<pair < ll , pair < pii , ll > >  > ,greater<pair < ll , pair < pii , ll > >  > > min_pq;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << std::endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
#define nn 2000005
vector < vector < ll > > adjlist ( N );
ll n;
ll col[ N ][ 5 ];
bool v[ N ];
ll ar[ N ];
ll colans[ N ];
ll dp[ N ][ 5 ][ 5 ];
bool move ( ll st ){
    ll node = st;
    v[node] = 1;
    ar[1] = node;
    for ( ll i = 1; i <= n-1; i ++){
        ll cnt = 0;
        ll kaun = 0;
        for ( auto it : adjlist[node] ){
            if (!v[it] ){
                v[it] = 1;
                kaun = it;
                cnt ++;
            }
        }
        if ( cnt >= 2 ){
            return 0;
        }
        node = kaun;
        ar[i+1] = node;
    }
    return 1;
}
ll vl[4][4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin >> n;
    for ( ll i = 1; i <= 3; i ++){
        for ( ll j = 1; j <= n; j ++){
            cin >> col[j][i];
        }
    }
    for ( ll i = 1; i <= n-1; i ++){
        ll a,b;
        cin >> a >> b;
        adjlist[a].pb(b);
        adjlist[b].pb(a);
    }
    ll st = -1;
    for ( ll i = 1; i <= n; i ++){
        if ( adjlist[i].size() == 1 ){
            st = i;
            break;
        }
    }
    if ( st == -1 ){
        cout <<"-1";
        return 0;
    }
    bool flg = move(st);
    if ( !flg ){
        cout <<"-1";
        return 0;
    }
    vl[1][3] = 2;
    vl[3][1] = 2;
    vl[2][3] = 1;
    vl[3][2] = 1;
    vl[1][2] = 3;
    vl[2][1] = 3;
    dp[2][1][2] = col[ar[1]][1] + col[ar[2]][2];
    dp[2][2][1] = col[ar[1]][2] + col[ar[2]][1];
    dp[2][1][3] = col[ar[1]][1] + col[ar[2]][3];
    dp[2][3][1] = col[ar[1]][3] + col[ar[2]][1];
    dp[2][2][3] = col[ar[1]][2] + col[ar[2]][3];
    dp[2][3][2] = col[ar[1]][3] + col[ar[2]][2];
    ll ans = MAXN;
    ll las = -1;
    ll slas = -1;
    for ( ll i = 3; i <= n; i ++){
        for ( ll j = 1; j <= 3; j ++){
            for ( ll k = 1; k <= 3; k ++){
                if ( j != k ){
                    dp[i][j][k] = dp[i-1][vl[j][k]][j] + col[ar[i]][k];
                    if ( i == n ){
                        if ( dp[i][j][k] < ans ){
                            ans = min(ans,dp[i][j][k]);
                            colans[ar[n-1]] = j;
                            colans[ar[n]] = k;
                        }
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    for ( ll i = n-2; i >= 1; i --){
        colans[ar[i]] = vl[colans[ar[i+1]]][colans[ar[i+2]]];
    }
    for ( ll i = 1; i <= n; i ++){
        cout << colans[i] <<" ";
    }
    
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   