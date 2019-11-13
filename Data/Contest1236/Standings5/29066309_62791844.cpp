#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<
//        pair<long long, int>, // change type
//        null_type,
//        less<pair<long long, int> >, // change type
//        rb_tree_tag,
//        tree_order_statistics_node_update>
//        ordered_set;

//template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
#define rep(i, start, end) for(int i = start; i < end; ++i)
#define sz(x) (int)(x).size()
#define pb push_back
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define clr(d, v) memset(d, v, sizeof(d))
#define pii pair<int, int>
#define debug(x) cerr << #x << " : " << (x) << endl
const double PI = 3.14159265358979323846;
const double eps = (1e-5);
int isGreater(long double x, long double y)
{
    if (abs(x - y) < eps)
        return 0;
    if (x > y)
        return 1;
    return -1;
}

const int MOD = 1000000007;

long long mult(long long x, long long y)
{
    return ((x%MOD) * (y%MOD))%MOD;
}

long long power(long long base, long long exp)
{
    long long ret = 1;
    for (; exp; exp /= 2)
    {
        if (exp&1)
            ret = mult(ret, base);
        base = mult(base, base);
    }
    return ret;
}

long long mod(long long x)
{
    return (x%MOD + MOD)%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//    freopen("facebook.txt", "w", stdout);
#endif
    long long n, m;
    cin >> n >> m;
    long long ans = mod(power(2, m) - 1);
    ans = power(ans, n);
    cout << ans << '\n';
    return 0;
}