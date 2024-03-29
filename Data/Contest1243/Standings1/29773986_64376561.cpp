#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define pb push_back
#define ft first
#define sd second
#define inf (int)1e9

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    ll k;

    cin >> k;

    for (ll x = 0; x < k; x++) {
        string s,t;
        ll n;

        cin >> n;

        cin >> s >> t;

        vector <ll> p;

        for (ll i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                p.pb(i);
            }
        }

        if (p.size() != 2) {
            cout << "No\n";
        }
        else {
            swap(s[p[0]],t[p[1]]);

            if (s != t) {
                cout << "No\n";
            }
            else {
                cout << "Yes\n";
            }
        }
    }
    return 0;
}