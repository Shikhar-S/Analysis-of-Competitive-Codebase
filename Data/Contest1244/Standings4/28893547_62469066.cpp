#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second

using namespace std;

const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const ll MAX = 5e18;

int T, a, b, c, d, k, x, y;

int main()
{
    cin >> T;
    while(T--){
        cin >> a >> b >> c >> d >> k;
        x = a / c + ((a % c ) > 0);
        y = b / d + ((b % d ) > 0);
        if(x + y > k)
            puts("-1");
        else
            printf("%d %d\n", x, y);
    }

    return 0;
}
