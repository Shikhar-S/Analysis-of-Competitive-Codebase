#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

using namespace std;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--){
      ll a, b; cin >> a >> b;
      if(__gcd(a, b) > 1) cout << "Infinite" << endl;
      else cout << "Finite" << endl;
    }
    return 0;
}
