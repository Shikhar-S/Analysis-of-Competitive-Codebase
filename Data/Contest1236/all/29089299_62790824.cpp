#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define MOD 1000000007
#define CAP 10000000
#define inf 1000000000000000000LL
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(v)    v.begin(),v.end()
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y>0){if(y&1)res = (res*x)%md;x = (x*x)%md;y = y>>1;}return res%md;}
#define dbg(x) cout <<#x<<":"<<x<<endl;
ll max1(ll a, ll b, ll c=-inf, ll d=-inf) {ll mx1=(a>b)?a:b, mx2=(c>d)?c:d; return ((mx1>mx2)?mx1:mx2);}
#define int ll

signed main() {
    fast;
    
    int n,m;
    cin>>n>>m;

    int ans = power(2,m) - 1;
    ans = power(ans,n);

    cout<<ans;

}