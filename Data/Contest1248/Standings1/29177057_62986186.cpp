#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll sc = 0;
    ll res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(')sc++;
        else sc--;
    }

    if(sc != 0)vout("0\n1 1\n");

    ll x, y;
    x = y = 0;

    for(int l = 0; l < n; l++)
        for(int r = l; r < n; r++){
            ll sum = 0, Min;
            Min = 1e18;
            ll kol = 0;
            swap(s[l], s[r]);
            for(auto j : s){
                if(j == '(')sum++;
                else sum--;
                Min = min(Min, sum);
            }
            if(Min > -1)kol++;

            for(int i = 0; i < n - 1; i++){
                ll val = 1;
                if(s[i] == '(')val = -1;
                Min += val;
                if(Min > -1)kol++;
            }
            if(kol > res){
                res = kol;
                x = l, y = r;
            }
            swap(s[l], s[r]);
        }

    cout << res << "\n" << x + 1 << " " << y + 1 << "\n";

    return 0;
}
