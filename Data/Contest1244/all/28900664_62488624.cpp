/*
Uruchamiamy samolot zwiadowczy ( + 500% do wzlamaniej )

/▄/  /█/  /&#9680;/   /▐/   /▌/ /▀/ /░/ /&#128293;/   choose  own style!

***IT'S OUR LONG WAY TO THE OIILLLL***


░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░▌░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░◐◐◐█████████▀▀▀▀▀▀🔥░░░░░░░░███░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░▌░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░█▌░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▀██████████████████████████████████████████████████
░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄████▄████████ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ █████
░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█████████▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░◐◐◐█████████▀▀▀▀▀▀🔥░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░░░░░░░░░░
*/


#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ll long long
#define ld long double
#define fi first
#define se second
#define eb emplace_back
#define pii pair < int , int >
#define pipii pair< int, pair < int , int > >
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T, null_type, less< T >, rb_tree_tag,tree_order_statistics_node_update>;


namespace fastio {
    template <class T> ostream &operator<<(ostream &os, const vector<T> &container){for (auto &u : container)os << u << " ";return os;}
    template<class T1, class T2> ostream& operator << (ostream& os, const pair<T1, T2>& p) { return os << p.first << " " << p.second; }
    template <class T> ostream &operator<<(ostream &os, set<T> const& con) { for (auto &u : con) os << u << " "; return os; }
    void pr() {}
    template <typename T, typename... args> void pr(T x, args... tail) { cout << x << " "; pr(tail...);}
}
using namespace fastio;


const int N = 1e5 + 15;
const int MA = 1e6;
const int M = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef Estb_probitie
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ll n, k;
    cin >> n >> k;
    int a[n], mx = -1, mn = 1e9 + 1;
    for (int i = 0; i < n; ++i)
        cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);

    vector < pair < ll, ll > > v1, v2;
    sort(a, a + n);
    int kol = 1;
    ll sum = 0;
    ll now = a[0];

    for (int i = 1; i < n; ++i)
    {
        int zn = 0;
        while(i + 1 < n && a[i] == a[i + 1])
            ++i, ++zn;
        v1.pb({kol, min(a[i] - now, (k - sum) / kol)});
        sum += kol * (a[i] - now);
        now = a[i];
        if (sum >= k)
            break;
        kol += zn + 1;
    }
    sum = 0;kol = 1;
    now = a[n - 1];

    for (int i = n - 2; i >= 0; --i)
    {
        int zn = 0;
        while(i && a[i - 1] == a[i])
            --i, ++zn;
        v2.pb({kol, min(now - a[i], (k - sum) / kol)});
        sum += kol * (now - a[i]);
        now = a[i];
        if (sum >= k)
            break;
        kol += zn + 1;
    }
//    cout<<v1<<endl;cout<<v2<<endl;
    int poz1 = 0, poz2 = 0, ans = 0;
    while(poz1 < n && !v1[poz1].fi) ++poz1;
    while(poz2 < n && !v2[poz2].fi) ++poz2;

    while(true)
    {
        ll c1 = 1e18, c2 = 1e18;

        if (poz1 < v1.size())
            c1 = v1[poz1].fi;
        if (poz2 < v2.size())
            c2 = v2[poz2].fi;
        if (c1 > k && c2 > k)
            break;

        if (c1 < c2)
        {
            kol = min(v1[poz1].se, k / c1);
            ans += kol;
            k -= kol * c1;
            ++poz1;
        } else
        {
            kol = min(v2[poz2].se, k / c2);
            ans += kol;
            k -= kol * c2;
            ++poz2;
        }
//        cout<<c1<<" "<<c2<<" "<<poz1<<" "<<poz2<<" "<<k<<" "<<kol<<" "<<ans<<endl;
    }

    cout << max(mx - mn - ans, 0);
}
