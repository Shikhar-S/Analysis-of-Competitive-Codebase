#include<bits/stdc++.h>

using namespace std;


#define ss second
#define ff first
#define int long long
//#define double long double
#define pb push_back

const int N = 1e6 + 1, MOD = 1e9 + 7, mod = 998244353, INF = 3e18;

mt19937 Flash_new_51(51515);

using vi = vector <int>;
using vp = vector <pair <int, int>>;

int ANS[2], lst[2];


signed main() {
   #ifdef Flash
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
   int t;
   cin >> t;
   while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int k1 = (a + c - 1) / c, k2 = (b + d - 1) / d;
        if (k1 + k2 <= k) {
            cout << k1 << ' ' << k - k1 << "\n";
        }
        else cout << "-1\n";
   }

}
