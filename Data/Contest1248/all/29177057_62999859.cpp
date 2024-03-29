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


    ll n, p;
    cin >> n >> p;

    vector <ll> t(n + 1), ans(n + 1);

    for(int i = 1; i <= n; i++)cin >> t[i];

    set <pll> d;

    for(int i = 1; i <= n; i++)d.insert({t[i], i});

    ll time = 0, kol = 0;

    set <ll> in_q, free;

    queue <ll> stack_in_q;

    ll last = 0;

    while(kol < n){

        while(!d.empty() && (*d.begin()).fi < time){
            pll xe = *d.begin();
            d.erase(d.begin());
            if(in_q.empty() && last > xe.se){
                in_q.insert(xe.se);
                stack_in_q.push(xe.se);
            }else{
                if(sz(in_q)){
                    if(min(*in_q.begin(), last) > xe.se){
                        in_q.insert(xe.se);
                        stack_in_q.push(xe.se);
                    }else free.insert(xe.se);
                }
                else free.insert(xe.se);
            }
        }

        while(!d.empty() && (*d.begin()).fi <= time){
            pll xe = *d.begin();
            d.erase(d.begin());
            free.insert(xe.se);
        }

        if(sz(free)){
            ll Mx = inf;
            if(sz(in_q))Mx = *in_q.begin();
            ll pos = *free.begin();
            if(pos < Mx){
                free.erase(free.begin());
                in_q.insert(pos);
                stack_in_q.push(pos);
            }
        }

        if(sz(in_q)){
            ll pos = stack_in_q.front();
            stack_in_q.pop();
            in_q.erase(pos);
            time += p;
            ans[pos] = time;
            kol++;
            last = pos;
        }else{
            time = (*d.begin()).fi;
            continue;
        }

    }

    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
