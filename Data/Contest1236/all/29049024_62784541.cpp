#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mk make_pair
#define ld long double
#define y1 asdfghjkl
#define ufo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r){
    return (mt_rnd_64() % (r-l+1)) + l;
}

int t,a,b,c,q,ans;

main()
{
    ufo;
    cin>>t;
    for(int T = 0;T < t;T++){
        cin>>a>>b>>c;
        ans = 0;
        q = min(b,c/2);
        ans = q*3;
        b -= q;
        c -= q*2;
        q = min(a,b/2);
        ans += q*3;
        cout<<ans<<'\n';
    }
}
