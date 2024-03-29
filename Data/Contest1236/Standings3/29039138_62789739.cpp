#include<bits/stdc++.h>

using namespace std;

using ll = long long int;
using vi = vector<int>;
#define f(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define c(n) cout << n << " ";
#define ci(n) cin >> n;
#define cn cout << "\n";
#define ic(n) int n; cin >> n;
#define lc(n) int n; cin >> n;
#define all(a) a.begin(), a.end()
#define pri(a, n) for(int i = 0; i < n; i++) cout << a[i] << " "; cout << "\n";
#define sc(a, n) int a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define scl(a, n) ll a[n] = {0}; for(int i = 0; i < n; i++) cin >> a[i];
#define pb push_back
#define eb emplace_back
#define int long long

const int mod = 1000000007;
int bp(int a, int n)
{
    if(n == 0) return 1;
    if(n & 1) return (a * bp(a, n - 1)) % mod;
    int res = bp(a, n / 2);
    return (res * res) % mod;
}
main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = bp(bp(2, m) - 1, n);
    cout << ans;
}
