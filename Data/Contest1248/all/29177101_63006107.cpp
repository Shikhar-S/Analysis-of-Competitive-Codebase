#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
ll const mod = 1e9+7;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

const int MAX_N = 100010;
ll fact[MAX_N],fact_inv[MAX_N],inv[MAX_N];

ll pow_mod(ll a,ll b) {
    ll ret;
    if (b < 0) ret = pow_mod(a,mod+b-1);
    else if (b == 0) ret = 1;
    else if (b == 1) ret = a;
    else {
        ll c = pow_mod(a,b/2);
        if (b%2) ret = (c*c)%mod*a%mod;
        else ret = c*c%mod;
    }
    return ret;
}

void genarate_table(int x) {
    fact[0] = 1;fact[1] = 1;
    for (int i = 2;i <= x;++i) fact[i] = fact[i-1]*i%mod;
    fact_inv[x] = pow_mod(fact[x],-1);
    for (int i = x;i > 0;--i) fact_inv[i-1] = fact_inv[i]*i%mod;
    for (int i = 1;i <= x;++i) inv[i] = fact_inv[i]*fact[i-1]%mod;
}

ll combi(ll a, ll b) {
    return fact[a]*fact_inv[b]%mod*fact_inv[a-b]%mod;
}

int main() {
    genarate_table(100000);
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = (n+1)/2;i <= n;++i) {
        (ans += combi(i,n-i)*2) %= mod;
    }
    for (int i = (m+1)/2;i < m;++i) {
        (ans += combi(i,m-i)*2) %= mod;
    }
    cout << ans << endl;
}