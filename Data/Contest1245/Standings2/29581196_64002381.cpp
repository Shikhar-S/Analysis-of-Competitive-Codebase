/* winners never quit and quitters never win.
      #swap                                 */
      
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
const ll inf = 1000000000000000000;
const ll rk = 256;

typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pb push_back
#define mp make_pair
#define vc vector
#define fs first
#define sec second
#define pq priority_queue
#define lb lower_bound
#define ub upper_bound
#define pll pair<ll,ll> 
#define pls pair<ll,string>
#define psl pair<string,ll>
#define plc pair<ll,char>
#define pcl pair<char,ll>
#define pss pair<string,string>
#define all(v) v.begin(),v.end()
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define T ll t=0;cin>>t;for(ll test=0;test<t;test++)

 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	//isprime();
	//coeff();
	/*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    map<char,ll> m;
    m['P']=1;
    m['S']=2;
    string s1="RPS";
    T
    {
        ll n;
        ll x[3];
        cin>>n>>x[0]>>x[1]>>x[2];
        string s;
        cin>>s;
        ll cnt=0;
        vector<char> ans(n,'.');
        rep(a,0,n)
        {
            ll b=m[s[a]];
            ll req=(b+1)%3;
            //cout<<b<<" "<<req<<endl;
            if(x[req]>0)
            {
                cnt++;
                x[req]--;
                ans[a]=s1[req];
            }
        }

        if(cnt>=(n+1)/2){
            cout<<"YES\n";
            rep(a,0,n)
            {
                if(ans[a]=='.')
                {
                    if(x[0])
                    {
                        cout<<"R";
                        x[0]--;
                    }
                    else if(x[1])
                    {
                        cout<<"P";
                        x[1]--;
                    }
                    else
                    {
                        cout<<"S";
                        x[2]--;
                    }
                }
                else
                    cout<<ans[a];
            }
            cout<<endl;
        }
        else
            cout<<"NO\n";
    }
	return 0;
}