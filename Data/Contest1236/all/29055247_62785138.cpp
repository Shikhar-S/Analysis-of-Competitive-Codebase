#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define x first
#define y second
#define ndl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)x.size()
#define bit __builtin_popcount
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using namespace __gnu_pbds;

template<typename T> using indexed_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<int, ull> piu;
typedef vector<vector<int>> matrix;

const ll INF = 1e18 + 123;
const ld EPS = 1e-9;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 5e5 + 123;
const int M = 1e6 + 123;
const double pi = acos(-1.0);
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main(){
    #ifdef KAZAKH
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i + i <= b; i++){
            int j = b - i - i;
            ans =max(ans, min(i, a) + min(j, c/2));
        }
        cout << ans * 3 << endl;
    }
    return 0;
}
