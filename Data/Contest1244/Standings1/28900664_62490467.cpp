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

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector < int > v;

        for (int i = 0; i < n; ++i)
            if (s[i] == '1')
                v.pb(i);
        if (!v.size())
        {
            cout << n << '\n';
            continue;
        }

        int ans = n;
        ans = max(ans, (v.back() + 1) * 2);
        ans = max(ans, (n - v[0]) * 2);
        cout << ans << '\n';
    }

}
