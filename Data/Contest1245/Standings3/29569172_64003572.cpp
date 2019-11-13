#pragma GCC target("avx2")
#pragma GCC optimize("O3")
    
#include <x86intrin.h>
#include <bits/stdc++.h>   
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
  
using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
      
#define F first
#define S second           
#define lb lower_bound               
#define ub upper_bound
#define pb push_back
#define pf push_front    
#define ppb pop_back
#define mp make_pair
#define bpp __builtin_popcountll                                                                                        
#define sqr(x) ((x) * (x)) 
#define al 0x3F3F3F3F
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define in insert
#define ppf pop_front
#define endl '\n'
//#define int long long
  
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
  
const int mod = (int)1e9 + 7;
const int N = (int)3e5 + 123;
const ll inf = (ll)1e18 + 1;
 
const double pi = acos (-1.0);
const double eps = 1e-7;                  
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

string s;
int dp[N], ans = 1;

inline int add (int a, int b) {
   a += b;
   if (a >= mod) a -= mod;
   return a;
}

inline int mult (int a, int b) {
   return 1ll * a * b % mod;
}

inline void boost () {                    
   ios_base :: sync_with_stdio (NULL);
   cin.tie (NULL), cout.tie (NULL);          
}                                                     
 
inline void Solve () {
   cin >> s;
   dp[1] = dp[0] = 1;
   for (int i = 2; i <= 100000; i ++) dp[i] = add (dp[i - 1], dp[i - 2]);
   bool ok = 0;
   for (int i = 0; i < sz (s); i ++) {  
      if (s[i] == 'm' || s[i] == 'w') cout << 0, exit (0);
      if (s[i] == 'u' || s[i] == 'n') {
         int j = i;
         while (j + 1 < sz (s) && s[j + 1] == s[i]) j ++;
         ans = mult (ans, dp[j - i + 1]);
         i = j;
      }
   }
   cout << ans;
}
 
main () {                                       
// freopen (".in", "r", stdin);    
// freopen (".out", "w", stdout);              
   boost ();
   int tt = 1;
   //cin >> tt;   
   while (tt --) {
      Solve ();
   }                                               
   return 0;      
}