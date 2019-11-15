// Running Offline
// g++ tester.cpp
// ./a.out

#include "bits/stdc++.h"
using namespace std;

#define SPEED       ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define filei       freopen("input.txt", "r", stdin);
#define fileio      freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout);
#define rep(i,a,b)  for(int i=a; i<b; i++)
#define int         long long int
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long long int,long long int>
#define sd(x)       scanf("%d",&x)
#define slld(x)     scanf("%lld",&x)
#define pd(x)       printf("%d\n",x)
#define plld(x)     printf("%lld\n",x)
#define pss         printf
#define MOD         1000000007
#define inf         1e18
#define eps         0.000001
#define endl        '\n'
#define N           200005
#define dbg(...)    cout<<"> "; ZZ(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1> void ZZ(const char* val1, Arg1&& arg1) { cerr<<val1<<": "<<arg1<<endl; }
template <typename Arg1, typename... Args> void ZZ(const char* vals, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(vals + 1, ',');
    std::cerr.write(vals, comma - vals) << ": " << arg1<<" , ";
    ZZ(comma+1, args...);
}

int power(int x, int y) 
{ 
    int res = 1;
    x = x%MOD;
    while(y!=0) {
        if(y&1)
            res = (res*x)%MOD;
        y = y>>1;
        x = (x*x)%MOD;
    }
    return res; 
}

int32_t main() {
    SPEED;
    int n, m;
    cin >> n >> m;
    cout << power(power(2, m) - 1 + MOD, n);
    return 0;
}